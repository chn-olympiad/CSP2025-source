#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t; 
	while(t--){
		int n;
		cin>>n;
		int aa=-1e9;
		int sum=0;
		int a1=0,a2=0,a3=0,b;
		int a[3][n+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				aa=max(aa,a[i][j]);
			}
			sum=sum+aa;
		}
		cout<<sum<<endl;
	}
	return 0;
}
