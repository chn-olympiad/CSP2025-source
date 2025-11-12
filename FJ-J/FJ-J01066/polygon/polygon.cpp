#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int sum=0;
	int n;
	int a[5000];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				int d=a[k];
				int e=a[i]+a[j]+a[k];
				if (d*2<e){
					sum++;
				}
			}
		}
	}
	if(n==3){
		cout << sum;
		return 0;
	}
	for(int i=0;i<n-3;i++){
		for(int j=i+1;j<n-2;j++){
			for(int k=j+1;k<n-1;k++){
				for (int l=k+1;l<n;l++){
					int d=a[l];
					int e=a[i]+a[j]+a[k]+a[l];
					if (d*2<e){
						sum++;
					}
				}
			}
		}
	}
	int d=a[4];
	int e=a[0]+a[1]+a[2]+a[3]+a[4];
	if(n==5&&d*2<e){
		sum++;
	}
	cout << sum%998244353;
	
	return 0;
}
