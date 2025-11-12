#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int M=1e4+5;
int n,m,k,sum,ans;
struct r{
	int s,e,v;
}road[N];
bool city[M];
int build[N];
int c[15][N];
bool cmp(r a,r b){
	return a.v<b.v;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>road[i].s>>road[i].e>>road[i].v;
	}
	for(int i=1;i<=k;i++){
		cin>>build[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	sort(road+1,road+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(city[road[i].s]&&city[road[i].e])continue;
		ans+=road[i].v;
		if(!city[road[i].s])sum++;
		if(!city[road[i].e])sum++;
		city[road[i].s]=1;
		city[road[i].e]=1;
		if(sum==n)break;
	} 
	cout<<ans;
	return 0;
}
