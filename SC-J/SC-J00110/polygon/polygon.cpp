#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef unsigned long long ulld;
ulld ans;
lld n,m,gs,sum,max1;int a[5100],s[5100],b[5100];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;m=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]]++;
		//if(s[a[i]]>1)a[i]=1e9,m--;
	}
	if(s[1]==n){
		ulld u;
		u=n*(n-1)*(n-2)/6%998244353;
		ans+=n*(n-1)*(n-2)/6%998244353;
		for(int i=4;i<=n;i++){
			u*=(n-i+1)%998244353;u/=i;u%=998244353;
			ans+=u;
		}
		cout<<ans;
		return 0;
	}else{
		sort(a+1,a+n+1);
		while(b[n+1]==0){
			b[1]++;
			int i=1;
			if(b[i]==2){
				while(b[i]==2){
					b[i]=0;sum-=a[i],gs--;
					b[i+1]++;i++;
				}
				sum+=a[i];gs++;
			}
			if(b[1]==1)sum+=a[1],gs++;
			else max1=max(max1,1ll*a[i]);
			if((gs>=3)&&(sum>(2*max1))){
				ans++;
				ans%=998244353;
			}
			//for(int i=1;i<=n;i++)cout<<b[i]<<' ';
			//printf("%lld %lld %lld %lld\n",sum,max1,gs,ans);
		}
		cout<<ans;
		return 0;
	}
}