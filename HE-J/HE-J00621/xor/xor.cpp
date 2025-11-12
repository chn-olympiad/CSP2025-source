#include<bits/stdc++.h>
using namespace std;

int n,k;
const int N=5e5+5;
int a[N],s[N],dp[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	if(n<=1e4){
		memset(dp,-0x3f,sizeof(dp));
		dp[0]=0;
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1];
			for(int j=1;j<=i;j++){
				int x=s[i]^s[j-1];
				if(x==k){
					dp[i]=max(dp[i],dp[j-1]+1);
				}
			}
		}
		cout<<dp[n];
	}
	else{
		int ans=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans;
		}
		else if(k==0){
			//如果是1 下一个也是1 就要这个区间
			//否则不要 因为0可以单拿出来 
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else if(a[i]==1){
					if(a[i+1]==1){
						a[i+1]=-1;
						ans++;
					}
				}
			}
			cout<<ans;
		}
		else{
			cout<<n/2;
		}
	}
	
	return 0;
}
