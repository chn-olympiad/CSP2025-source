#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5005],f[5005],cnt,ans;
long long q1,q2,q3;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		for(int q1=1;q1<=n;q1++){
			for(int q2=q1+1;q2<=n;q2++){
				for(int q3=q2+1;q3<=n;q3++){
				    long long maxn=2*max(a[q1],max(a[q2],a[q3]));
					if(a[q1]+a[q2]+a[q3]>maxn) ans++;
				}
			}
		}
	}else{
		for(long long i=1;i<=n-2;i++){
			ans+=(i*(i+1)/2);
		}
	}
	cout<<ans%998244353;
	return 0;
}

