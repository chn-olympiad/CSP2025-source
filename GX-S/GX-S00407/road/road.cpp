#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("raod.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,b,c;
	cin>>n>>m>>k;
	int sum=0;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		sum+=c;
	}
	cout<<sum;
}
