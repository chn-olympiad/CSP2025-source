#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
const int p=998244353;
int n,a[N],dp[2*N];
bool cmp(int a,int b){
	return a>b;
}
ll quickly_pow(int a,int n){
	ll ans=1;
	while(n){
		if(n&1)ans=(ans%p*a%p)%p;
		a=(a%p*a%p)%p;
		n>>=1;
	}
	return ans;
}
int main(){
	//freopen("polygon1.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	ll ans=0;
	for(int i=1;i<=n;i++){
		dp[2*a[i]]=0;
		for(int u=i+1;u<=n;u++){
		
				for(int j=2*a[i];j>=0;j--){
					if(j>=a[u]){
						dp[j]+=dp[j-a[u]]+1;
					}
				}
				cout<<u<<" "<<2*a[i]<<" "<<dp[2*a[i]]<<endl;
			
		}
		ans=(ans%p+dp[2*a[i]]%p)%p;
	}
	cout<<(quickly_pow(2,n)-ans)%p;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

