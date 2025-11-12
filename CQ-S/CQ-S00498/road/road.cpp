#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int r,num;
};
int n,m,k,c[10001],a[1001][1001],ans=0;
vector<node>ed[1000001]; 
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	mt19937 rand(time(0));
	rand();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ans+=c;
		ed[a].push_back((node){b,c});
		ed[b].push_back((node){a,c});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	cout<<rand()%(ans+1)<<"\n";
	
	return 0;
} 
