#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[20],a[30][100010],fl[100010];
vector <pair<int,int> > g[100010],gx[100010];
int read(){
	char ch=getchar();
	while(ch<'0'&&ch>'9'){
		ch=getchar();
	}
	int s=0;
	while('0'<=ch&&ch<='9'){
		s=s*10+(ch-'0');
		ch=getchar();
	}
	return s;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		int x,y,z;
		x=read();
		y=read();
		z=read();
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	int res=1e18;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	for(int i=0;i<=(1ll<<(k-1));i++){
		for(int j=1;j<=n;j++){
			gx[j].clear();
			fl[j]=0;
		}
		for(int j=1;j<=n;j++){
			for(auto y:g[j]){
				gx[j].push_back(y);
			}
		}
		int cnt=m;
		int ans=0;
		for(int j=1;j<=k;j++){
			if(i&(1ll<<(j-1))){
//				cout<<1;
				for(int l=1;l<=n;l++){
					gx[j+n].push_back({l,a[j][l]});
					gx[l].push_back({j+n,a[j][l]});
				}
				ans+=c[j];
			}
//			else cout<<0;
		}
//		cout<<"\nhello\n";
//		cout<<cnt<<" "<<"hello\n"<<endl;
		priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
		q.push({0,1});
		while(!q.empty()){
			int x=q.top().second;
			int l=q.top().first;
			q.pop();
			if(fl[x]) continue;
			fl[x]=1;
			ans+=l;
			for(auto y:gx[x]){
				if(fl[y.first]) continue;
				q.push({y.second,y.first});
			}
		}
//		cout<<endl;
//		cout<<ans<<endl;
		res=min(res,ans);
	}
	cout<<res<<endl;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
