#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int sum=0;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		sum+=c;
	}
	for(int i=1;i<=k;i++){
		for(int i=1;i<=n;i++){
			int t;
			cin>>t;
		}
	}
	cout<<sum;
	return 0;
}
