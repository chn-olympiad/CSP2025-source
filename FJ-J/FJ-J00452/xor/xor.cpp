#include<bits/stdc++.h>
using namespace std;
int a[500050],b,n,m,ans,sum,k,cnt;
void dfs(int t,int yh,int c){
	if(t>n){
		ans=max(ans,c);
	}
	else{int d=yh^a[t];
		if(d==k){
			dfs(t+1,0,c+1);
		}
		else{
			dfs(t+1,0,c);
			dfs(t+1,d,c);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];sum=max(sum,a[i]);
	}
	if(sum==1&&n>10){
		if(k==0)
		for(int i=1;i<=n;i++){
			if(a[i]==1)cnt++;
			if(a[i]==0)ans++,cnt=0;
			if(cnt==2)ans++,cnt=0;
		}
		if(k==1){
			for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		}
	}
	else dfs(1,0,0);
	cout<<ans;
	return 0;
}






