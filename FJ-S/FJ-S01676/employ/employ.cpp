#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int MOD=998244353;
int n,m;
string s;
long long ans;
int c[N],t[N];
bool book[N];
bool flag;
int flag_cnt;
int check(){
	int tot=0,sum=0;
	for(int i=1;i<=n;i++){
		if(tot>=c[t[i]]){
			tot++;
			continue;
		}
		if(s[i-1]=='0'){
			tot++;
		}else{
			tot=0;
			sum++;
		}
	}
	if(sum>=m)return 1;
	else return 0;
}
void dfs(int cnt){
	if(cnt==n+1){
		if(check()){
			ans++;
			ans%=MOD;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(book[i])continue;
		t[cnt]=i;
		book[i]=1;
		dfs(cnt+1);
		book[i]=0; 
	}
}
void solve1(){
	ans=0;
	dfs(1);
	cout<<ans;
}
void solve2(){
	if(m>=n-flag_cnt){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=MOD;
		}
	}
	cout<<ans;
}
void solve3(){
	if(flag==1||flag_cnt>0){
		cout<<0;
		return ;
	}else{
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
		return ;
	} 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)if(s[i]=='0')flag=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)flag_cnt++;
	}
	if(flag==0){
		solve2();
		return 0;
	}
	if(m==n){
		solve3();
		return 0;
	}
	solve1();
	return 0;
}
