#include<bits/stdc++.h>
using namespace std;
int sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005]={};
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				if((max(max(a[i],a[j]),a[k]))*2<a[i]+a[j]+a[k]){
					sum++;
				}
			}
		}
	}
	cout << sum;
	return 0;
}
