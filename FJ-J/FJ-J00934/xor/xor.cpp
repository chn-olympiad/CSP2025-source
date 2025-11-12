#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,k,a[N],sum[N],lst[N],dp[N],c[N],vis[2*N],vis_num[2*N];
int lowbit(int x){
	return x&(-x);
}
void add(int x,int k){
	for(int i=x;i<=n;i+=lowbit(i))c[i]=max(c[i],k);
}
int query(int x){
	int maxx=0;
	for(int i=x;i;i-=lowbit(i))maxx=max(maxx,c[i]);
	return maxx;
}
int main(){
	freopen("xor1.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		int p=k^sum[i];
		if(a[i]==k)lst[i]=i;
		else if(!p && !vis_num[p])lst[i]=1;
		else if(!vis_num[p])lst[i]=0;
		else lst[i]=vis[p]+1;
		vis[sum[i]]=i;
		vis_num[sum[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if(!lst[i])dp[i]=dp[i-1];
		else{
			int u=query(lst[i]-1);
			dp[i]=max(dp[i-1],u+1);
		}
		add(i,dp[i]);
	}
	cout<<dp[n]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

