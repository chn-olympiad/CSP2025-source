#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n;
int a[100010],b[100010],c[100010];
ll ans;
int t1,t2;
void dfs(int k,ll cnt,int sum1,int sum2){
	if(sum1*2>n||sum2*2>n||2*k>n+2+2*sum2+2*sum1) return ;
//	cout<<k<<' '<<cnt<<' '<<sum1<<' '<<sum2<<' '<<k-sum1-sum2-1<<endl;
	if(k==n+1){
		ans=max(ans,cnt);
		return ;
	}
	dfs(k+1,cnt+a[k],sum1+1,sum2);
	dfs(k+1,cnt+b[k],sum1,sum2+1);
	dfs(k+1,cnt+c[k],sum1,sum2); 
}
void dfs2(int k,ll cnt,int sum1,int sum2){
	if(sum1*2>n||sum2*2>n) return ;
//	cout<<k<<' '<<cnt<<' '<<sum1<<' '<<sum2<<' '<<k-sum1-sum2-1<<endl;
	if(k==n+1){
		ans=max(ans,cnt);
		return ;
	}
	dfs(k+1,cnt+a[k],sum1+1,sum2);
	dfs(k+1,cnt+b[k],sum1,sum2+1);
}
void solve(){
	cin>>n;
	ans=t1=t2=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>b[i]>>c[i];
		t1+=(b[i]==0);
		t2+=(c[i]==0);
	}
	if(t1==n&&t2==n){
		sort(a+1,a+1+n);
		for(int i=n/2+1;i<=n;i++)
		{
			ans+=a[i];
		}
		cout<<ans<<endl;
		return ;
	} 
	else if(t2==n){
		dfs2(1,0,0,0);
		cout<<ans<<endl;
		return ;
	}
	dfs(1,0,0,0);
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}


