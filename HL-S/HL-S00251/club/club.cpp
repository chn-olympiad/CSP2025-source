#include<bits/stdc++.h>
using namespace std;
int dp[505][505][1005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		int k=0,sum=0;
		int a1[n],a2[n],a3[n];
	}
	int a[n+15];
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
		if(n%2==1){
			return 0;
		}
		cin>>a1[n]>>a2[n]>>a3[n];
}
		for(int i=1;i<=3;i++){
		if(a1[n]>n/2&&a2[n]>n/2&&a3[n]>n/2){
				return 0;
			}
	}
}
    sort(a1,a1+1,a1+1+n);
    sort(a2,a2+1,a2+1+n);
    sort(a3,a3+1,a3+1+n);
    for(int i=1;i<=n;i++){
    	if(a1>a1+1>a1+1+n){
    		sum+=a1;
		}else if(a1+1>a1>a1+1+n){
			sum+=a1+1;
		}
		else{
			sum+=a1+1+n;
		}
		cout<<sum;
		if(a2>a2+1>a2+1+n){
    		sum+=a2;
		}else if(a2+1>a2>a2+1+n){
			sum+=a2+1;
		}
		else{
			sum+=a2+1+n;
		}
		cout<<sum;
		if(a3>a3+1>a3+1+n){
    		sum+=a3;
		}else if(a3+1>a3>a3+1+n){
			sum+=a3+1;
		}
		else{
			sum+=a3+1+n;
	    }
	}
	k=dp(sum,sum+1,sum+1+n);
	cout<<k;
	return 0;
}
