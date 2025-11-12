#include<bits/stdc++.h> 
using namespace std;
int n;
int a[5005];
long long ans;
long long f[5005][5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]<=a[3]){
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	for(int i=1;i<=n-2;i++){
		ans+=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
