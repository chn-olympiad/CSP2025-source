#include <bits/stdc++.h>
using namespace std;
int a[100000][3];
int b[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0,n=0;
	cin>>t;
	if (t==1){
		cin>>n;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		if (n>=100000){
			for (int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n);
			int sum=0;
			for (int i=n;i>=n/2;i--){
				sum+=b[i];
			}
			cout<<sum;
		}
	}
	return 0;
}
