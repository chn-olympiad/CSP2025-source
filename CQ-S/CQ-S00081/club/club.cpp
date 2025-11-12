#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define D long double
#define lbt(x) ((x)&(-(x)))
#define N 200005
int a[N][4],b[N],n,in[N][4],to[N][4][4],sz[4];
priority_queue<pair<int,int> > q[4][4];
inline void gin(int i,int x){
	for(int j=1;j<=3;j++)if(j!=x){
		q[x][j].push({to[i][x][j],i});
	}
	in[i][x]=1;sz[x]++;
}
inline void out(int i,int j){
	while(q[i][j].size()&&(!in[q[i][j].top().second][i]))	q[i][j].pop();
}
inline int getval(int i,int x){
	if(sz[x]<n/2)	return a[i][x];
	int mx=-1e9;
	for(int j=1;j<=3;j++)if(j!=x){
		out(x,j);
		int v=q[x][j].top().first;mx=max(mx,v);
	}
	return a[i][x]+mx;
}
inline void getpq(int i,int x){
	if(sz[x]<n/2){
		gin(i,x);return;
	}
	int mx=-1e9,pos=1;
	for(int j=1;j<=3;j++)if(j!=x){
		out(x,j);
		int v=q[x][j].top().first;
		if(v>mx){
			mx=v;pos=j;
		}
	}
	in[q[x][pos].top().second][x]=0;sz[x]--;
	gin(q[x][pos].top().second,pos);gin(i,x);
}
inline int getin(int now){
	int mx=-1,pos=1;
	for(int i=1;i<=3;i++){
		int v=getval(now,i);
		if(v>mx){
			mx=v;pos=i;
		}
		//cerr<<"NOW: "<<now<<" "<<i<<" : "<<v<<"   "<<sz[i]<<endl;
	}
	getpq(now,pos);
	return mx;
}
inline void solve(){
	cin>>n;
	for(int i=1;i<=3;i++){
		sz[i]=0;
		for(int j=1;j<=3;j++){
			while(q[i][j].size())	q[i][j].pop();
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++)if(j!=k){
				to[i][j][k]=a[i][k]-a[i][j];
			}
			in[i][j]=0;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=getin(i);
		//cerr<<"NOW: "<<i<<"  "<<sz[1]<<" "<<sz[2]<<" "<<sz[3]<<endl;
	}
	cout<<sum<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--)	solve();
	return 0;
}
