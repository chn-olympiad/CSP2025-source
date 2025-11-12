#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,sum,ans;
vector<int>a[10005];
map<pair<int,int>,int> b;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		b[{x,y}]=z;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int l=0;l<k;l++){
				sum=min(a[l][0]+a[l][i]+a[l][j],sum);
			}
			ans+=min(sum,b[{i,j}]);               
		}
	}
	cout<<ans;
	return 0;
}

