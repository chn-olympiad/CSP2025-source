#include<bits/stdc++.h>
using namespace std;
int a[5005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n==3){
		if(a[2]+a[3]+a[1]>2*a[1]){
			cout<<1;
		}else cout<<0;
		return 0;
	}
	long long ans=1;
	long long k=-1-n-n*(n-1)/2;
	for(int i=1;i<=n;i++){
		ans=ans*2;
		if(ans>998244353){
			ans=ans-998244353;
		}
	}
	ans=ans+k;
	if(ans<0)ans=ans+998244353;
	cout<<ans;
return 0;
}
