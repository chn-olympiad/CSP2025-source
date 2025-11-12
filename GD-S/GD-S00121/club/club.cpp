#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define lowbit(x) (x)&(-x)
using namespace std;
const int N=1e5+10;
ll ans;
vi v[4];
int n,m,T,a[N],b[N],c[4];
inline int read(){
	int s=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return f?-s:s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		ans=0;
		v[1].clear(),v[2].clear(),v[3].clear();
		for(register int i=1;i<=n;++i){
			for(register int j=1;j<=3;++j) c[j]=read();
			int mx=0,mx2=0,pos=0;
			for(register int j=1;j<=3;++j){
				if(mx<c[j]) mx2=mx,mx=c[j],pos=j;
				else mx2=max(mx2,c[j]);
			}
			v[pos].pb(mx-mx2);ans+=mx;
		}
		for(register int i=1;i<=3;++i){
			sort(v[i].begin(),v[i].end());
			int tot=v[i].size();
			for(register int j=0;j<tot-n/2;++j) ans-=v[i][j];
		}
		cout<<ans<<'\n';
	}
	return 0;
}

