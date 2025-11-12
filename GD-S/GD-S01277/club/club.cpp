#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int scarr[10000]= {0};
	int t;
	cin>>t;
	for(int k=1; k<=t; k++) {
		int n;
		cin>>n;
		int arr[1000][1000]= {0};
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				cin>>arr[i][j];
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				if(n<=i) {
					scarr[i]+=max(arr[i][j],max(arr[i+1][j],max(arr[i+2][j],max(arr[i+3][j],max(arr[i+4][j],arr[i+4][j])))));
				}
			}
			int ch=n-i+n;
			for(int h=1; h<=ch; h++) {
				scarr[i]+=max(arr[i][h],max(arr[i+1][h],max(arr[i+2][h],max(arr[i+3][h],max(arr[i+4][h],arr[i+4][h])))));
			}
		}
	}
	for(int i=1; i<=t; i++) {
		cout<<scarr[i]<<endl;
	}
	return 0;
}
