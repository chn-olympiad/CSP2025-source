#include<bits/stdc++.h>
using namespace std;
map<string,int> dp;
int a[5010];
int ans;int n;
void dfs(string s,int i,int maxn,int flag){
	if(dp[s]>maxn*2&&s.size()>2&&flag==1){
		ans++;
	}
	if(i>n){
		return;
	}
	dp[s+'0']=dp[s];
	dp[s+'1']=dp[s]+a[i];
	dfs(s+'0',i+1,maxn,0);
	dfs(s+'1',i+1,a[i],1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp["1"]=a[1];
	dp["0"]=0;
	dp["10"]=a[1];
	dp["00"]=0;
	dp["11"]=a[1]+a[2];
	dp["01"]=a[2];
	string s="";
	dfs("10",3,a[1],0);
	dfs("00",3,0,0);
	dfs("11",3,a[2],1);
	dfs("01",3,a[2],1);
	cout<<ans;
	return 0;
}
