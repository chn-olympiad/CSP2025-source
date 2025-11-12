#include <bits/stdc++.h>
using namespace std;
int n; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int he=0,maxi=-1;
			for(int q=i;q<=j;q++){
				he+=a[q];
				maxi=(a[q]>maxi?a[q]:maxi); 
			}
			if(he>maxi*2){
				ans++;
				ans%=998244353;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

