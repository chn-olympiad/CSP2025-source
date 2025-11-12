#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=9982443553;
int n,a[5005],ans=0;
bool vis[5005];
int findmax(){
	int cnt=-0x7f7f7f7f;
	for(int i=1;i<=n;i++)
	if(vis[i]==0 && a[i]>cnt) cnt=a[i];
	return cnt;
}
void dfs(int sum,int x,int y){ // 总长度为 sum，最长为 x，选了 y个
	if(y<3||sum<=x*2) return;
	ans++;
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		dfs(sum-a[i],findmax(),y-1);
		vis[i]=0; // 回溯
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int num=0;
	for(int i=1;i<=n;i++) num+=a[i];
	if(n<3) cout<<"0"<<endl;
	else if(n==3){
		int sum=a[1]+a[2]+a[3];
		if(sum<=a[3]*2) cout<<"0"<<endl;
		else cout<<"1"<<endl;
	}//12分(1-3)
	else if(num==n){
		n-=2;
		cout<<((n+1)*n)/2<<endl;
	}//24分(15-20)
	else{
		memset(vis,0,sizeof(vis));
		dfs(num,a[n],n);
		cout<<ans%mod<<endl;
	}
	return 0;
}
//CSP一等，rp++， lol 