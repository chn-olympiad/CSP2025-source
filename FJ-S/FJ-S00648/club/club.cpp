// Author: Mr_Az
// Finish Time: 2025-11-01 14£º58£º34 

#include<bits/stdc++.h>
#define rint register int
//#define int long long
#define pb push_back
#define eb emplace_back
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	x=x*f;
	return ;
}
namespace Mr_Az{
	int T=0;
	const int N=1e5+8;
	int n;
	ll ans;
	int a[N][3],b[N][3],cnt[3];
	vector<int> c[3];
	inline void clear(){
		ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		c[0].clear();c[1].clear();c[2].clear();
		return ;
	}
	inline void solve(){
		clear();
		read(n);
		for(rint i=1;i<=n;i++){
//			cerr<<i<<": "<<endl;
			read(a[i][0]);read(a[i][1]);read(a[i][2]);
			b[i][0]=min({a[i][0],a[i][1],a[i][2]});
			b[i][2]=max({a[i][0],a[i][1],a[i][2]});
			b[i][1]=a[i][0]+a[i][1]+a[i][2]-b[i][0]-b[i][2];
			int tt; 
			if(b[i][2]==a[i][0]) tt=0;
			else if(b[i][2]==a[i][1]) tt=1;
			else tt=2;
			c[tt].pb(b[i][2]-b[i][1]);cnt[tt]++;
			ans+=b[i][2];
//			cerr<<b[i][0]<<" "<<b[i][1]<<" "<<b[i][2]<<" "<<tt<<endl;
		}
		int t=max({cnt[0],cnt[1],cnt[2]}),p;
//		cout<<t<<" "<<n/2<<endl;
		if(t==n/2){printf("%lld\n",ans);return ;}
		if(t==cnt[0]) p=0;
		if(t==cnt[1]) p=1;
		if(t==cnt[2]) p=2;
		sort(c[p].begin(),c[p].end());
		for(rint i=0;i<(int)(c[p].size())-n/2;i++) ans-=c[p][i];
		printf("%lld\n",ans);
		return ;
	}
	inline void mian(){if(!T) read(T);while(T--) solve();}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int st=clock();
	Mr_Az::mian();
	int ed=clock();
	cerr<<"time use: "<<ed-st<<" ms.\n"<<endl;
	return 0;
}
