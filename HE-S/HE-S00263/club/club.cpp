#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,f=0;
	cin>>t;
	cin>>n;
	int a[n+1][t];
	for(int i=1;i<=t;i++){
		for(int j=1;i<=n;j++){
			cin>>a[i][j];	
		}
	}
	int max;
	for(int i=1;i<=t;i++){
		cout<<a[i][1];
	}
	return 0;
}
