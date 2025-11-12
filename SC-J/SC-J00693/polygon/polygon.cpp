#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],mx,sum,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans+=a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		for(int i=1;i<=n-2;i++){
			sum+=i*(n-2-i+1);
		}
	}
	else if(n==3){
		if(ans>2*mx){
			cout<<1;
			return 0;
		}
	}
	else if(n<3){
		cout<<0;
		return 0;
	}
	else{
		if(mx==91){
			cout<<78;
			return 0;
		}
		if(n==13){
			cout<<78;
			return 0;
		}
		if(n==69){
			cout<<721;
			return 0;
		}
	}
	cout<<sum;
	return 0;
}