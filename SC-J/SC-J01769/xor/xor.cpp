#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],ans=0;
bool oa=true,ob=true;
void dfs(int now,int num,int cnt,int len){
	if(len>0 and cnt==k) num++,cnt=0,len=0;
	if(now==n+1){
		ans=max(ans,num);
		return ;
	}
	if(n-now+num<ans) return ;
	dfs(now+1,num,cnt^a[now],len+1);
	dfs(now+1,num,0,0);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) oa=false;
		if(a[i]>1) ob=false;
	}
	if(oa){
		if(k==1) cout<<n;
		else if(k==0) cout<<n/2;
		else cout<<"0";
		return 0;
	}
	if(ob){
		if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans;
		}
		else if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(i!=1 and a[i-1]==1 and a[i]==1) a[i]=0,ans++;
			}
			cout<<ans;
		}
		else cout<<"0";
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}