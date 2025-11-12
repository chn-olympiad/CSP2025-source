#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e6+10,mod=998244353;
ll n,m,c[maxn],flg1=1,flg0=1;
ll qpow(ll x,ll y){
	if(y==0)return 1;
	if(y==1)return x;
	ll p=qpow(x,y/2);
	return p*p*(y&1?x:1)%mod;
}char s[maxn];
ll ans;
ll vis[maxn],cnt,rd;//有多少人跑路 有多少人入职 
ll tmp[maxn],top;
bool check(){
	cnt=0,rd=0;
	for(int i=1;i<=n;i++){
//		cout<<cnt<<' '<<rd<<endl;
		if(c[tmp[i]]<=cnt||s[i]=='0')cnt++;
		else rd++;
		
	}
//	if(rd>=m){
//		for(int i=1;i<=n;i++){
//			cout<<tmp[i]<<' ';
//		}cout<<endl;
//	}
	return rd>=m;
}
void dfs(ll len){
	//cout<<len<<' ';
//	if(len==n)cout<<1<<' ';
	if(len>=n){
		ans+=check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
//		if(i==3&&len==0)cout<<"q";
		//cout<<i<<' ';
		vis[i]=1;
		tmp[++top]=i;
		dfs(len+1);
		vis[i]=0;
		top--;
	}
}
void solve(){
	dfs(0);
	cout<<ans;

}
int main(){//cout<<qpow(2,62);
//	freopen("employ2.in","r",stdin);


	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	
	cin>>n>>m;
	
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	tmp[1]=2,tmp[2]=1,tmp[3]=3;
//	cout<<check();
	
	for(int i=1;i<=n;i++){
		flg1&=(s[i]=='1');
		flg0&=(s[i]=='0');
	}solve();
//	cout<<flg1<<' ';
	return 0;
} /*
3 2
101
1 1 2
*/
