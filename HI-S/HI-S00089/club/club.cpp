#include <bits/stdc++.h>
using namespace std;
int n,a[100005][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			cin>>n;
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			} 
		}
	}
	return 0;
} 
