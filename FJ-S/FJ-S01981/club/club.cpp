//15:00
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long Rd;

inline Rd read(){Rd xxx=0,yyy=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')yyy*=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){xxx=(xxx<<1)+(xxx<<3)+(ch^48);ch=getchar();}
return xxx*yyy;
}

const int maxn=100005;

int t,n,cnt;
int tot[5],usd[maxn];
struct node_{
	ll val;int c;
	bool operator <(const node_&T)const{return val>T.val;}
}v[5];
struct node{
	ll val,ca,wz;int id,c;
	bool operator <(const node&T)const{return wz==T.wz?ca>T.ca:wz<T.wz;}
}a[maxn*3];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;cnt=0;
		tot[1]=tot[2]=tot[3]=0;
		for(int i=1;i<=n;i++){
			usd[i]=0;
			for(int j=1;j<=3;j++)
				v[j].val=read(),
				v[j].c=j;
			sort(v+1,v+3+1);
			for(int j=1;j<=3;j++){
				a[++cnt].id=i,
				a[cnt].c=v[j].c,
				a[cnt].val=v[j].val;
				if(j==3)a[cnt].ca=0;
				else a[cnt].ca=v[j].val-v[j+1].val;
				a[cnt].wz=j;
			}
		}
		sort(a+1,a+cnt+1);
		ll ans=0;
		for(int i=1;i<=cnt;i++){
			if(usd[a[i].id]||tot[a[i].c]+1>n/2)continue;
			ans+=a[i].val,usd[a[i].id]=1,tot[a[i].c]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
