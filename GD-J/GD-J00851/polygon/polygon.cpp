#include<bits/stdc++.h>
using namespace std;
int n,a[5005],k=1;
long long ans=1;
void f(int n){
	for(int i=1;i<=n;i++) ans=(ans*2)%998244353;
	ans=ans-1-n-n*(n-1)/2;
}
int main(){
	freopen("polygen.in","r",stdin);
	freopen("polygen.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3] > 2*a[3]) cout<<1;
		else cout<<0;
	}
	else if(a[n]==1){
		f(n);
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
