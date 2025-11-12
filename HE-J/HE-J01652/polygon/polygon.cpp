#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int top;
int s[50000];
int a[50000];
int vis[50000];
void dfs(int len,long long sum,int ma,int seat){
	if(len==0){
		if(sum>2*ma){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	if(sum>10000){
		ans++;
		ans%=998244353;
		return ;
	}
	for(int i=seat;i<=n;i++){
		if(vis[i]==0){
			s[len]=a[i];
			vis[i]=1;
			dfs(len-1,sum+a[i],max(ma,a[i]),i+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int len=3;len<=n;len++){
		top=len;
		dfs(len,0,0,1);
	}
	cout<<ans;
	return 0;
}

