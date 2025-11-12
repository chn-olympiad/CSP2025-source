#include<bits/stdc++.h>
using namespace std;
int n,m,sum,a[n][m];
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			cout<<a[i][j];
			}
		}
		
	return 0;
	}
