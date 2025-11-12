#include<bits/stdc++.h>
using namespace std;
int n,a[5001],dp[5001];
int F(int x){
	int length=0,sum=0;
	for(int j=x-1;j>=1;j--){
		length+=a[j];
		if(length>a[x]) sum++;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n==3){
		for(int i=3;i<=n;i++){
			for(int j=i-1;j<i;j++){
				for(int k=j-1;k<j;k++){
					if(a[j]+a[k]>a[i]) sum++;
				}
			}
		} 
	}
	else if(n==4){
		for(int i=4;i<=n;i++){
			for(int j=i-1;j<i;j++){
				for(int k=j-1;k<j;k++){
					for(int d=k-1;d<k;d++){
						if(a[j]+a[k]+a[d]>a[i]) sum++;
					}
					
				}
			}
		} 
	}
	else if(n==5){
		for(int i=4;i<=n;i++){
			for(int j=i-1;j<i;j++){
				for(int k=j-1;k<j;k++){
					for(int d=k-1;d<k;d++){
						for(int p=d-1;p<d;p++){
							if(a[j]+a[k]+a[d]+a[p]>a[i]) sum++;
						}
						
					}
					
				}
			}
		} 
	}
	cout<<sum;

	return 0;
}
