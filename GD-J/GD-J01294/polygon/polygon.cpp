#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
const int N=5e3;
ll n,a[N+5],C[N+5][N+5],maxx,ans,sum1,cnt;
vector<int>v;
void yh(){
	C[0][0]=1;
	for(int i=1;i<=N;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
}
void func(int start){
	for(int i=start;i<=n;i++){
		ans+=C[n][i];
		ans%=mod;
	}
}
void dfs(int now,int num,int sum,int choose){
	if(now>n||num>=cnt) return;
	if(num>=3&&sum>2*a[now]&&choose) ans++;
	ans%=mod;
	dfs(now+1,num,sum,0);
	dfs(now+1,num+1,sum+a[now+1],1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	yh();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(maxx==1){
		func(3);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum1+=a[i];
		if(sum1>2*maxx){
			cnt=i;
			break;
		}
	}
	func(cnt);
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
