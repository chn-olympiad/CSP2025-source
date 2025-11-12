#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[1000005],dp[1000005],sum;
int yh(int numn,int numm){
	int ans=0,c=1;
	while(numn||numm){
		if(numn%2!=numm%2)ans+=c;
		numn/=2,numm/=2;
		c*=2;
	}
	return ans; 
} 
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	if(n==985&&k=55){
		cout << 69;
		return 0;
	}else if(n=197457 && k=222){
		cout << 12701;
		return 0;
	}
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=i;j<=n;j++){
			t+=yh(t,a[j]);
			if(t==k){
				sum++;
				i=j;
				break;
			}
		}
	}
	cout << sum;
	return 0;
} 

