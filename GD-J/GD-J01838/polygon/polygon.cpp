#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,s[5001],p[5001];
int ans=0;
const int inf=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		p[s[i]]++;
	}
	if(p[1]==n){
		int p=1,q=1,ans=0;
		for(int i=1,j=n;i<=n;i++,j--){
			p=(p*j+inf)%inf,q=(q*i+inf)%inf;
			if(i>=3) ans+=(p/q+inf)%inf;
			ans%=inf;
		}
		cout<<ans;
		return 0;
	}
	int p,j,sum,mx,k;
	int o=0;
	for(int i=1;i<=(1<<n)-1;i++){
		p=i,j=0,sum=0,mx=0,k=0;
		while(p){
			j++;
			if(p%2==1){
				sum+=s[j];
				mx=max(mx,s[j]);
			}
			p/=2;
		}
		if(sum>mx*2) ans++;
		ans%=inf;
	}
	cout<<ans;
	return 0;
}
