#include <bits/stdc++.h>
using namespace std;

const int N=5e3+5,mod=998244353;
int n,a[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	 
	//2^n±©Á¦Ã¶¾Ù
	int ans=0;
	for(int i=1;i<(1<<n);i++){
		int sum=0,maxn=0;
		for(int k=0;k<n;k++){
			if((i>>k)&1){
				maxn=max(maxn,a[k+1]);
				sum+=a[k+1];
			}
		}
		if(sum>maxn*2)ans=(ans+1)%mod;
	} 
	cout<<ans<<'\n';
	return 0; 
}
