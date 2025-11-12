#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const long long Mod=998244353;
int n,a[5010],su[5010],ma[505][505],cnt,sum,m;
long long ans;

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		su[i]+=a[i]+su[i-1];
	}
	if(n<=3){
		m=max({a[1],a[2],a[3]});
		if(a[1]+a[2]+a[3]>m*2) ans++;
		cout<<ans;
		return 0;
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int l=j;l<=i;l++){
				sum=max(sum,a[l]);
			}
			ma[i][j]=sum;
			sum=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i-2;j++){
			cnt=su[i]-su[j-1];
			if(cnt>2*ma[i][j]){
				ans++;
				ans%=Mod;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
