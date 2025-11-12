#include<bits/stdc++.h>
using namespace std;
int n;
int num[5003];
int c[5003];
long long ans=0;
bool check(){
	int sum=0,maxn=0;
	for(int i=1;i<=n;i++){
		if(c[i]){
			maxn=max(maxn,num[i]);
			sum+=num[i];
		}
	}
	if(sum>maxn*2){
		return true;
	}
	return false;
}
void dfs(int x){
	if(x>n){
		if(check()){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	c[x]=1;
	dfs(x+1);
	c[x]=0;
	dfs(x+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
