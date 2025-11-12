#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int x,y,u;
		cin>>x>>y>>u;
		sum+=u;
	}
	cout<<sum;
	return 0;
}
