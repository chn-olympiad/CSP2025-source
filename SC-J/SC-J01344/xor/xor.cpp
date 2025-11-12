#include<bits/stdc++.h>
#define lowbit(i) i&-i
#define N (int)5e5+5
#define inf ((int)(1<<20)+5)
using namespace std;
int n,k;
int a[N],su[N];
int v[inf];
int pre[N];
int dp[N];
void add(int x,int y){
	for(int i=x;i<=n;i+=lowbit(i)){
		dp[i]=max(dp[i],y);
	}
	return ;
}
int query(int x){
	int ret=0;
	for(int i=x;i>=1;i-=lowbit(i)){
		ret=max(ret,dp[i]);
	}
	return ret;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<=inf;i++){
		v[i]=-1;
	} 
	su[0]=0;v[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		su[i]=su[i-1]^a[i];
		pre[i]=v[su[i]^k];
		v[su[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(pre[i]<0)continue;
		add(i,query(pre[i])+1);
	}
	cout<<query(n);
	return 0;
}