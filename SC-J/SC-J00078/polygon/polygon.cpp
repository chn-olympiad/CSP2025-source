#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
int a[5005],used[5005];
void dfs(int b,int k,int g,int zh,int ma){
	if(k==b){
		if(zh>ma){
			cnt++;
			cnt%=998244353;
		} 
		return ;
	}
	for(int i=g;i<=n;i++)
	{
		if(used[i]==0){
			used[i]=1;
			int ma1=ma;
			dfs(b,k+1,i,zh+a[i],max(ma,2*a[i]));
			used[i]=0;
			ma=ma1;
		}
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
	for(int i=3;i<=n+1;i++){
		dfs(i,1,1,0,-1);
		memset(used,0,sizeof(used));
	}
	cout<<cnt;
	return 0;
}