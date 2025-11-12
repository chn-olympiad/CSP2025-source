#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout<<#x<<'='<<x<<endl;
#define ll long long
const ll mod=998244353;
int n;
ll ans;
int a[5010];
int b[5010];
ll fun[5010];
void solve(int step,int cnt){
	if(step==n+1){
		if(cnt>=3){
			int sum=0;
			int mx=0;
			for(int i=1;i<=n;i++){
				if(b[i]){
					sum+=a[i];
					mx=a[i];
				}
			}
			if(sum>2*mx)ans++,ans%=mod;
		}
		return ;
	}
	for(int i=0;i<=1;i++){
		b[step]=i;
		if(i)solve(step+1,cnt+1);
		else solve(step+1,cnt);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=25){
		solve(1,0);
		cout<<ans<<endl;
	}
	else{
		fun[1]=1;
		fun[0]=1;
		for(int i=2;i<=n;i++){
			fun[i]=fun[i-1]*(1ll*i)%mod;
		}
		for(int i=3;i<=n;i++){
			ll now=1;
			for(int j=n;j>=n-i+1;j--){
				now=now*fun[n]%mod/(fun[i]*fun[n-i]%mod)%mod;
			}
			ans=(ans+now)%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
