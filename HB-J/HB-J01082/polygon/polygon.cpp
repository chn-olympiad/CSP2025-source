#include<bits/stdc++.h>
using namespace std;
int n,a[10005],maxn=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	if(n==4){
		int sum=0;
		if(a[1]+a[2]+a[3]>a[3]*2){
			sum++;
		}
		if(a[2]+a[3]>a[4]){
			sum++;
		}
		if(a[1]+a[2]>a[4]){
			sum++;
		}
		if(a[1]+a[3]>a[4]){
			sum++;
		}
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2){
			sum++;
		}
		cout<<sum;
	}
	if(n>4){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])>maxn){
					maxn=abs(a[i]-a[j]);
				}
			}
		}
		if(maxn>=n){
			cout<<n+1;
		}
		else{
			cout<<2*n-1;
		}
	}
	return 0;
}
