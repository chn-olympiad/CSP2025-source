#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int Rd;

inline Rd read(){Rd xxx=0,yyy=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')yyy*=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){xxx=(xxx<<1)+(xxx<<3)+(ch^48);ch=getchar();}
return xxx*yyy;
}inline int gt(){char ch=getchar();
while(ch!='0'&&ch!='1')ch=getchar();
if(ch=='1')return 1;
return 0;
}

const int maxn=25,mod=998244353;

int n,m;
ll ans;
int a[maxn],c[maxn],v[maxn],b[maxn];

void print(){for(int i=1;i<=n;i++)cout<<b[i]<<' ';cout<<ans<<endl;
}

void dfs(int x,int sum){
	if(x==n+1){ans+=(sum>=m);/*print();*/return;}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			b[x]=i;
			dfs(x+1,sum+((a[x]&&c[i]>x-1-sum)?1:0));
			v[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;a[i++]=gt());
	for(int i=1;i<=n;c[i++]=read());
	dfs(1,0);
	cout<<ans;
	return 0;
}
