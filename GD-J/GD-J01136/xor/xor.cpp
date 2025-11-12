 #include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,k,a[500005],sm[500005],ans,dp[1005][1005];
void dfs(int t,int cnt){
	if(t==n+1){
		ans=max(ans,cnt);
		return;
	}
	for(int i=t;i<=n;i++){
		if((sm[i]^sm[t-1])==k){
			dfs(i+1,cnt+1);
		}
	}
	dfs(t+1,cnt);
	return;
}
signed main(){
	IOS
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	sm[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sm[i]=(sm[i-1]^a[i]);
	}
	if(k==0){
		int flag=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=1){
				flag=1;
				break;
			}
		}
		if(flag==0){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==a[i+1]) cnt++;
				else ans+=(cnt+1)/2,cnt=0;
			}
			cout<<ans<<endl;
			return 0;
		}
	}
	else if(k==1){
		int flag=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=1&&a[i]!=0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			int cnt=0;
			for(int i=1;i<=n;i++) if(a[i]==1) ans++;
			cout<<ans<<endl;
			return 0;
		}
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
} 
