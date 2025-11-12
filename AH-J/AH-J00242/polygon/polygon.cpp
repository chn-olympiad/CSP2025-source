#include<bits/stdc++.h>
#define mx(a,b,c) max(a,max(b,c))
typedef long long ll;
using namespace std;
const int N = 5e3+5;
const int mod = 998244353;
ll a[N],n,ans;
int k;
void dfs(int step,ll s,ll m,int cnt,int w){
	k++;
	if(cnt>=3&&s>2*m&&w!=-1)
	{
		ans++;ans%=mod;
		//printf("k:%d s:%lld max:%lld cnt:%d\n",k,s,m,cnt);
	}
	if(step<n){
			dfs(step+1,s,m,cnt,-1);
		dfs(step+1,s+a[step+1],max(m,a[step+1]),cnt+1,1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n<3)cout<<0;
	if(n==3){
		int w=mx(a[1],a[2],a[3]);
		int s=a[1]+a[2]+a[3];
		if(s>2*w)cout<<1;
		else cout<<0;
	}
	else if(n<=20){
		dfs(0,0,0,0,1);
		cout<<ans;
	}
	return 0;
}
