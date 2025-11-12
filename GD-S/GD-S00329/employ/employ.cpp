#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
const long long MOD=998244353;
int n,m,arr[N];
long long A[N],ans,cnt_0;
bool p[N];
string s;
void dfs(int nw,int cnt,int num){
	if(cnt+num>n-m) return ;
	if(nw>n){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(p[i]) continue;
		p[i]=true;
		int nc=cnt+(s[nw-1]=='0'),nn=num+(cnt+num>=arr[i]);
		dfs(nw+1,nc,nn);
		p[i]=false;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;
	A[0]=1;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		cnt_0+=(arr[i]==0);
		A[i]=A[i-1]*(long long)i;
		A[i]%=MOD;
	}
	bool f=true;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			f=false;
			break;
		}
	}
	if(cnt_0>n-m){
		cout<<0;
		return 0;
	}
	if(f){
		cout<<A[n];
		return 0;
	}//特殊性质A:无论排列如何,都有至少m个人会被面试
	dfs(1,0,0); 
	cout<<ans;
	return 0;
}
/*
employ特殊性质A+暴力版 

愿此行,终抵群星 泉门永存 
I love ldyy
icebird_ldyy code
*/
