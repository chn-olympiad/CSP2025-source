#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[5005];
int s[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	for(int i=n;i>=3;i--){
		if(a[i]*2>=s[i]) continue;
		int x=s[i]-a[i]*2-1;
		ans++;
		for(int j=1;j<=i-1;j++){
			for(int k=j;k<=i-1;k++){
				if((s[k]-s[j-1])<=x) ans++; 
			}
		}
		for(int j=1;j<=i-1;j++){
			for(int k=j+2;k<=i-1;k++){
				if((a[j]+a[k])<=x) ans++; 
			}
		}
		ans%=998244353;
	}
	cout<<ans;
	return 0;
} 
