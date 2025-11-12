#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int o[m];
	int t,s;
	int p=0;
	for(int q=0;q<m;q++){
		cin>>t>>s>>o[q];
		p+=o[q];
	}
	cout<<p;
	return 0;
}
