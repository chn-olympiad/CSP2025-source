#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
inline int read(){
	int x=0,f=1; char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}
const int N=1e5+5;
int n,a[N][5],b[N][5],mst[N],vis[N],d[N],cnt[4];
void solve(){
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	n=read();
	rep(i,1,n){
		rep(j,1,3){
			b[i][j]=a[i][j]=read();
		}
		int mx=0,p=0;
		rep(j,1,3){
			if(a[i][j]>mx) mx=a[i][j],p=j;
		}
		cnt[p]++,mst[i]=p;
	}
	int p=0,mx1=0,ans=0;
	rep(i,1,3) if(cnt[i]>mx1) mx1=cnt[i],p=i;
	if(cnt[p]<=n/2){
		rep(i,1,n){
			int mx=0;
			rep(j,1,3){
				mx=max(a[i][j],mx);
			}
			ans+=mx;
		}
		printf("%lld\n",ans);
		return;
	}
	//add something
	//
	vector<pair<int,int> > v;
	rep(i,1,n){
		if(mst[i]!=p) continue;
		sort(b[i]+1,b[i]+4,greater<int>());
		v.push_back({b[i][1]-b[i][2],i});
	}
	sort(v.begin(),v.end(),greater<pair<int,int> >());
	for(int i=0;i<=n/2-1;i++){
		vis[v[i].second]=1;
	}
	// int ans=0;
	rep(i,1,n){
		if(vis[i]) ans+=a[i][p];
		else{
			int mx=0;
			rep(j,1,3){
				if(j==p) continue;
				mx=max(mx,a[i][j]);
			}
			ans+=mx;
		} 
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _=read();
	while(_--) solve();
	return 0;
}