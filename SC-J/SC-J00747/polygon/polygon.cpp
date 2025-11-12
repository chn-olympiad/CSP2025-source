#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],s[5005],sum,as1,h;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			as1++;
		}
	}
	if(as1==n){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){ 
			h=s[j]-s[i-1];
			for(int u=0;u<j;u++){
				if(u==0 || u>i){
					h-=a[u];
					if(h>a[j]*2){
						sum++;
						sum%=998244353;
					}
					h=s[j]-s[i-1];
				}
			}
				
		}
	}
	cout<<sum%998244353;
	return 0;
}