#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005];
long long ans=0;
bool check1(int x,int y){
	if((2*x)<y)return 1;
	return 0;
}
long long c(int m){
	long long ans=1;
	int x=max(n-m,m),y=min(n-m,m);
	for(int i=x+1;i<=n;i++)ans=((ans*i)%mod);
	for(int i=y;i>1;i--)ans=((ans/i)%mod);
	return ans;
}
long long ans1;
void dfs(int x,int y,int maxn,int cnt,int zb){
	if(y>=x)return;
	if(zb<0)return;
	for(int i=zb;i>=0;i--){
		int tmp1=maxn,tmp2=cnt;
		maxn=max(maxn,a[i]);
		cnt+=a[i]; 
		if(check1(maxn,cnt)&&(x==(y+1))){
			ans1=(ans1+1)%mod;
			//	cout<<x<<' '<<y<<' '<<maxn<<' '<<cnt<<' '<<ans1<<'\n'; 
		}
		if(!check1(maxn,cnt)&&(x==(y+1)))break;
		dfs(x,y+1,maxn,cnt,i-1);
		maxn=tmp1;
		cnt=tmp2;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a,a+n);
	if(n==3){
		if(a[0]+a[1]<=a[2]){
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	if(a[n-1]==1){
		ans=0;
		for(int i=3;i<=n;i++){
			ans=(ans+c(i))%mod;
		}
		cout<<ans;
		return 0;
	}
	int x=a[0];
	bool flag=0;
	for(int i=1;i<n;i++){
		if(x==a[i])continue;
		flag=1;		
	}
	if(!flag){
		ans=0;
		for(int i=3;i<=n;i++){
			ans=(ans+c(i))%mod;
		}
		cout<<ans;
		return 0;		
	}
	for(int i=3;i<=n;i++)dfs(i,0,0,0,n-1);
	cout<<(ans1%mod);
	return 0;
} 
