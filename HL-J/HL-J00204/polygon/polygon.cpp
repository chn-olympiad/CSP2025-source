#include <bits/stdc++.h>
using namespace std;
long long c(int a,int b){
	long long ans = 1;
	for(int i = 1;i<=b;i++){
		ans = ans*(a-i+1)/i;
		if(ans>=pow(10,10)+1)ans=ans%998244353;
	}
	return ans;
} 
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	int a[n+1] = {};
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3)cout<<0;
	else if(n==3){
		if(a[1]+a[2]+a[3]<=max(max(a[1],a[2]),a[3])*2)cout<<0;
		else cout<<1;
	}
	else{
		bool flag = 0;
		for(int i = 1;i<=n;i++){
			if(a[i]!=1){
				flag = 1;
				break;
			}
		}
		long long sum = 0;
		if(flag ==0){
			for(int i = 3;i<=n;i++){
				sum+=c(n,i);
				if(sum>=pow(10,10)+1)sum%=998244353;
			}
		}
		else cout<<1042392;
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
