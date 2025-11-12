#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],k,dp[N],f[105];
vector<int>g[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,i,j,ans=0;
	cin>>n>>k;
	bool flag=1,flaga=1;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0||a[i]>1) flag=0;
		if(a[i]!=1) flaga=0;
	}
	if(flag){
		for(i=1;i<=n;i++){
			if(k==1&&a[i]==1) ans++;
			if(k==0&&a[i]==0) ans++;
		}
		if(k==1){
			cout<<ans;
			return 0;
		}
		int xb=0;
		for(i=1;i<n;i++){
			if(!a[i]) continue;
			if(xb<i&&a[i]&&a[i+1]) ans++,xb=i+1;
		}
		cout<<ans;
		return 0;
	}
	if(flaga&&k==0){
		cout<<n/2;
		return 0;
	}
	if(n<=5000){
		if(a[1]==k) dp[1]=1;
		for(i=2;i<=n;i++){
			int now=a[i];
			for(j=i-1;j>=0;j--){
				int t=0;
				if(now==k) t=1;
				dp[i]=max(dp[i],dp[j]+t);
				now^=a[j];
			}
			dp[i]=max(dp[i],dp[i-1]);
	//		cout<<dp[i]<<"\n";
		}
		cout<<dp[n];
	}
	else{
		int l=1,ans=0;
		for(i=1;i<=n;i++){
			int xb=0,t=a[i];
			while(t){
				if(t%2) f[xb]++;
				t/=2,xb++;
			}
			t=0;
			for(j=0;j<=8;j++) if(f[j]%2) t=t*10+(1<<j);
			if(t==k){
				ans++;
				g[i].push_back(l);
				for(j=l;j<i;j++){
					int xb=0,t=a[j];
					while(t){
						if(t%2) f[xb]--;
						t/=2,xb++;
					}
				}
				l=i;
			}
		}
		cout<<ans;
	}
	return 0;
}