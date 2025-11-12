#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n,ans;
ll a[5005];
ll yanghui[5005];
const long long mod=998244353;

bool cmp(int x,int y){
	return x>y;
}

bool vis[5005];

void dfs(ll nowid,ll nowmax,ll nowlenth,ll nowchosen){
	if(nowchosen>2&&(2*nowmax<nowlenth)){
		ans=(ans%mod+yanghui[n-nowid+1]%mod)%mod;
		return ;
	}
	if(nowid>n)return ;
	dfs(nowid+1,max(nowmax,a[nowid]),nowlenth+a[nowid],nowchosen+1);
	dfs(nowid+1,nowmax,nowlenth,nowchosen);
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	yanghui[0]=1;
	for(int i=1;i<=5000;i++){
		yanghui[i]=yanghui[i-1]*2;
		yanghui[i]%=mod;
	}
	cin>>n;
	bool allone=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)allone=0;
	}
	if(allone==1){
		cout<<((yanghui[n]-n-1)%mod-(n-1)*n/2%mod)%mod;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}