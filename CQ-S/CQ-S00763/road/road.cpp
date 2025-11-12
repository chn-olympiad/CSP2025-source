#include <bits/stdc++.h>
using namespace std;
long long n,m,k,cnt,h[1000005],t[1000005],dp[1000005],ans;
struct z{
	long long to,next,d;
}a[1000005];
void add(long long x,long long y,long long z){
	a[++cnt].next=y;
	a[cnt].d=z;
	h[x]=cnt;
	a[cnt].to=x;
}

void Z(){
	dp[1]=0;
	for(int i=1;i<=m;i++){
		long long minn=INT_MAX,minn_i=0;
		for(int j=1;j<=m;j++){
			if(dp[j]!=INT_MAX&&dp[j]!=-1&&dp[j]<minn){
				minn=dp[j];
				minn_i=j;
			}
		}
		if(minn==INT_MAX){
			break; 
		}
		ans+=minn;
		dp[minn_i]=-1;
		bool vis[1000005]={};
		for(int j=h[minn_i];j;j=a[j].next){
			long long v=a[j].to;
			if(vis[v]){
				break;
			}
			vis[v]=1;
			dp[v]=min(dp[v],a[v].d);
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		long long x,y,z;
		cin >> x >> y >> z;
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=1000004;i++){
		dp[i]=INT_MAX;
	}
	for(int i=1;i<=k;i++){
		cin >> t[i];
		for(int j=1;j<=n;j++){
			long long z;
			cin >> z;
			add(i,j,z);
			add(j,i,z);
		}
	}
	Z();
	cout << ans;
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

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
