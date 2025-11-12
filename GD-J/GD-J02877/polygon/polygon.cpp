#include <bits/stdc++.h>
using namespace std;
int n,a[5002],k,result,maxx=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin >>a[i];
	}
	for (int i=1;i<(1<<n+1);i++){
		int sum=0;
		for (int j=1;j<=n;j++){
			if (i & 1<<j){
				k++;
				sum += a[j];
				maxx = max(maxx,a[j]);
			}
		}
		if (k>=3)if(2*maxx < sum){
			result++;
		}
	}
	cout << result/2;
	return 0;
}
