#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
long long cnt[5005];
int a[114514];
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	else if(a[n]==1){
		long long p=0;
		for(int i=1;i<=n;i++){
			long long q=1;
			for(int j=n;j>=n-i+1;j--){
				q*=j;
				if(n-j+1<=i){
					q/=(n-j+1);
				}
				q%=MOD;
			}
			cout<<q<<endl;
			p=(p+q)%MOD;
		}
		cout<<(p+MOD-n-n*(n+1)/2)%MOD;
		return 0;
	}
	return 0;
}
