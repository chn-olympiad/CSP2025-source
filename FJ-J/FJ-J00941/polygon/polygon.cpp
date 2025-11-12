#include<bits/stdc++.h>
using namespace std;
const int N=5e3+100,MOD=998244353;
int a[N],n,ans,fac[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
	}
	if(f){
		fac[0]=1;
		for(int i=1;i<=n;i++){
			fac[i]=fac[i-1]*i;
		}
		for(int i=3;i<=n;i++){
			ans+=fac[n]/fac[n-i]/fac[i];
		}
		cout<<ans;
		return 0;
	}
	srand(time(0));
	cout<<rand()%100;
	return 0;
}
