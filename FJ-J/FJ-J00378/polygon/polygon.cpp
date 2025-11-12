#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '/n'
int n;
int a[5005];
bool v[5005];
ll ans=0;
bool cc(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			return false;
		}
	}
	return true;
}
void dfs(int d_f,int sum,int de){
	if(de>n){
		ans++;
		ans%=998244353;
		return ;
	}
	for(int i=d_f;i<=n;i++){
		if(v[i]==1)continue;
		if(a[i]<=sum)continue;
		dfs(d_f+1,a[i]+sum,de+1);
		v[i]=0;
	}
	return ;
}
void solveZ(){
	for(int i=3;i<=n;i++){
		dfs(i,a[i],1);
	}
	cout<<ans;
	return ;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	if(cc()==true){
		cout<<(n-2)%998244353;
	}else
	if(n<=3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		solveZ();
	}
	return 0;
}
