#include<bits/stdc++.h>
#define ull unsigned long long
#define qwe(i,l,r) for(int i=l;i<=r;++i)
#define ewq(i,l,r) for(int i=l;i>=r;--i)
#define mkp make_pair
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		f=ch=='-'?-f:f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int N=515;
int n,m,a[N],b[N],ans;
char s[N];
bool v[N];
void dfs(int u){
	if(u==n+1){
		int sum=0;
		qwe(i,1,n)if(s[i]=='0'||sum>=a[b[i]])++sum;
		if(n-sum>=m)++ans;
		return;
	}
	qwe(i,1,n){
		if(!v[i]){
			v[i]=1;
			b[u]=i;
			dfs(u+1);
			v[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	cin>>(s+1);
	qwe(i,1,n)a[i]=read();
	if(n>20){
		if(m==0){
			ans=1;
			qwe(i,2,n)ans=ans*i%998244353;
		}cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
