#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int n,a[N],num[N];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(long long i=7;i<(2<<(n-1));i++){
		int mx=0,sum=0,j=i,t=0;
		while(j){
			t++;
			if(j%2)sum+=a[t],mx=max(a[t],mx);
			j/=2;
		}
		if(sum>2*mx)ans++,ans%=mod;
	}
	cout<<ans;
	return 0;
}
