#include<bits/stdc++.h>
using namespace std;
long long a[2000005],b[1000000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,maxn=-1;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=3){
		if(2*maxn>b[n])	cout<<1;
		else cout<<0;
	}else if(maxn==1){
		int ans=0;
		for(int i=3;i<=n;i++){
			long long j1=n-i;
			long double s=1;
			while(j1>1){
				s/=j1;
				j1--;
			}
			for(long long j=i+1;j<=n;j++){
				s*=j;
				if(s>=998244353){
					long long q=floor(s);
					long double o=s-q;
					q%=998244353;
					s=q+o;
				}
			}
			ans+=(long long)s;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}
