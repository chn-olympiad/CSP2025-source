#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=998244353;
ll n,a[5001],f[5001],t[5001],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f[0]=t[0]=1;
	for(int i=1;i<n;i++){
		int sum=0;
		for(int j=a[n];j>=0;j--){
			if(j>=a[i])f[j]=(f[j]+f[j-a[i]])%p;
			if(j<=a[i+1])sum=(sum+f[j])%p;
		}
		t[i]=t[i-1]*2%p;
		ans=((ans+t[i]-sum)%p+p)%p;
	}
	cout<<ans;
}
