#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5010];
long long s[5010];
void dfs(int x,int len,long long sum,long long mx,int op){
	if(len>=3&&sum>mx*2&&op==1){
		ans++;
	}
	if(x==n+1)return;
	if(sum+s[x]<=mx*2)return;
	if(!mx){
		dfs(x+1,len+1,sum+a[x],a[x],1);
	}
	else{
		dfs(x+1,len+1,sum+a[x],mx,1);
	}
	dfs(x+1,len,sum,mx,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		s[i]=s[i+1]+a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	dfs(1,0,0,0,1);
	cout<<ans;
	return 0;
}
