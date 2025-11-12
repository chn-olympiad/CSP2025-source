#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
int a[5005];
bool cmp(int a,int b){
	return a>b;
}
long long ans=0;
int rrr=0,st_sum=0;
int st[50005];
void ins(int x){
	st[++rrr]=x;
	st_sum+=x;
	return;
}
void del(){
	st_sum-=st[rrr];
	rrr--;
}
bool check(){
	if(rrr<3){
		return 0;
	}
	if(st_sum>st[1]*2){
		return 1;
	}else{
		return 0;
	}
	
}
void dfs(int l){
	if(check()){
		ans++;
		ans%=mod;
	}
	for(int i=l+1;i<=n;i++){
		ins(a[i]);
		dfs(i);
		del();
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	dfs(0);
	cout<<ans;
	return 0;
}//40pts