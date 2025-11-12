#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,a[N],c[N],sum,me[N];
int in[N],cnt;
long long ans;
bool vis[N];
bool fs=1;
void solve(int x){
	if (x==0){
		int num=0;
		for (int i=1;i<=cnt;i++){
			int s=in[i];
			if (a[i]==0)num++;
			else{
				if (num>=c[s])num++;
			}
		}
		if (n-num>=m)ans++;
	}
	cnt++;
	for (int i=1;i<=n;i++){
		if (vis[i])continue;
		in[cnt]=i;vis[i]=1;
		solve(x-1);
		vis[i]=0;
	}
	cnt--;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		char x;cin>>x;
		a[i]=x-'0';
		if (a[i]!=1)fs=0;
	}
	for (int i=1;i<=n;i++){
		cin>>c[i];
		if (c[i]>0)sum++;
	}
	if (sum<m){
		cout<<0;
		return 0;
	}
	if (n<=10){
		ans=0;
		solve(n);
		cout<<ans;
	}else if (m==1){
		ans=1;
		int xx=0;
		for (int i=1;i<=n;i++){
			if (a[i]==1){
				for (int j=1;j<=n;j++){
					if (c[j]<=i-1)me[i]++;
				}
				if (me[i]<xx){
					int summ=1;
					for (int tt=1;tt<=n;tt++){
						summ*=tt;
						sum%=mod;
					}
					cout<<summ;
					return 0;
				}
				ans*=me[i]-xx;
				ans%=mod;
			}
		}
		xx++;
		for (int i=n-xx;i>=1;i--){
			ans*=i;
			ans%=mod;
		}
		int summ=1;
		for (int i=1;i<=n;i++){
			summ*=i;
			sum%=mod;
		}
		ans=sum+mod-ans;
		ans%=mod;
		cout<<ans;
	}else if (fs){
		ans=1;
		for (int i=n;i>=1;i--){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}
