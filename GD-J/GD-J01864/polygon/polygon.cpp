#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,l[5005]={},dp[5005]={},ml=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++) cin>>l[i];
	sort(l,l+n);
	for(int i=0;i<n;i++){
		ml=max(ml,l[i]);
		if(i>=2){
			long long sum=0;
			for(int j=i;j>=0;j--){
				sum+=l[i];
				if(sum>2*ml) ans++; 
				ans%=998244353;
			}
		}
	}
	ans%=998244353;
	cout<<ans;
	return 0;
}
