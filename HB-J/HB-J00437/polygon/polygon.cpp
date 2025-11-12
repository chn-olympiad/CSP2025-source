#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int sum1=0;
			for(int k=j;k<=j+i-1;k++){
				sum1+=a[k];
				if(k==j+i-1){
					if(sum1>a[k]*2){
						sum++;
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
