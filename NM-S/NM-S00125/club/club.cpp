#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin >> t;
	int sum=0;
	for(int i=1;i<=t;++i){
		cin >> n;
		int a[n][3];
		for(int j=1;i<=n;++j){
			for(int k=1;k<=3;++k){
				cin >> a[i][j];
				if(a[j][1]>a[j][2] && a[j][1]>a[j][3]){
					sum+=a[j][1];
				}	
				if(a[j][2]>a[j][1] && a[j][2]>a[j][3]){		
					sum+=a[j][2];
				}
				if(a[j][3]>a[j][1] && a[j][3]>a[j][2]){
					sum+=a[j][3];
				}
			}
		}
	}
	cout << sum;
    return 0;
}
