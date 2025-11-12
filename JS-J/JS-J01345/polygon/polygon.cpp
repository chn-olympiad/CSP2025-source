#include<bits/stdc++.h>
using namespace std;
int n;
int a[5000];;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k++){
				for(int l=k;l<=n;l++){
					if(a[i]+a[j]+a[k]>a[k]*2 || a[i]+a[j]+a[k]+a[l]>2*a[l]){
						cnt++;
					}
				}
			}
		}
	}
	cout << cnt%998244353;
	return 0;
}
