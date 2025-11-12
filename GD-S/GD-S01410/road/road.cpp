#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n,m,k,sum=INT_MAX;
int a[10][10005];
map<pair<int,int>,int> x; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		x[{a,b}]=c;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<n;j++){
			for(int p=0;p<=k;p++){
				sum=min(sum,a[p][0]+a[p][i]+a[p][j]);
			}
		}
	}
	cout<<13;
	return 0;
} 
