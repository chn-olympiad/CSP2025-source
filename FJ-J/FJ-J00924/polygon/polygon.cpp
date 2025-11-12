#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if((a[0]+a[1])>a[2]&&(a[0]+a[2])>a[1]&&(a[1]+a[2])>a[0]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		ans[3]=1;
		int sum=1;
		for(int i=4;i<=n;i++){
			sum+=i-2;
			ans[i]=2*ans[i-1]+sum;
			ans[i]%=998244353;
		}
		cout<<ans[n];
	}
	return 0;
}

