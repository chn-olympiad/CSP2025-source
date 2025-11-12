#include<bits/stdc++.h>
using namespace std;
long long n,t,m,a[100][100],b[100][100],c[100][100];
int main(){
	freopen("club","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++){
		cin>>n;
		for (int j=1;j<=n;j++){
			cin>>a[i][j]>>b[i][j]>>c[i][j];
		}
	}
	return 0;}
