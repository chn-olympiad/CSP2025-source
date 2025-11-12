#include<bits/stdc++.h>
#define int long long
#define mkp make_pair
using namespace std;
pair<int,pair<int,int>>bian[2000010];
int c[20],book[110010],l[10010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,cnt=0,u,v,w,x;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		bian[++cnt]=mkp(w,mkp(u,v));
	}
//	for(int i=1;i<=k;i++){
//		cin>>c[i];
//		for(int j=1;j<=n;j++){
//			cin>>l[j];
////			bian[++cnt]=mkp(x,mkp(n+i,j));
//		}
//		for(int x=1;x<=n;x++){
//			for(int y=x+1;y<=n;y++){
//				if(l[x]+l[y]<dis[x][y]||bk[x][y]==0)bian[++cnt]=mkp(l[x]+l[y],mkp(x,y)),dis[x][y]=l[x]+l[y];
//			}
//		}
//	}
	int ans=0,nowbk=0;
	sort(bian+1,bian+cnt+1);
	for(int i=1;i<=cnt;i++){
		int x=bian[i].second.first,y=bian[i].second.second,len=bian[i].first;
		if(!book[x]||!book[y]){
			ans+=len;
			nowbk+=2-book[x]-book[y];
			book[x]=1;
			book[y]=1;
		}
		if(nowbk==n)break;
	}
	cout<<ans;
	return 0;
}
//16pts
