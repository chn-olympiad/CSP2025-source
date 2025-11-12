#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int sum=0;
	for(int i=0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		sum+=c;
	}
	int ab,dp=0;
	ab=max(sum,dp);
	cout<<sum<<endl;
	return 0;
}
