#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long n,k,a[510000],ans;
ll b[51000][51000];
//b[i][j]表示区间i ~ j的异或结果,有i项
ll pi[51000],pj[51000],len;
ll vis[51000];
ll ch[51000];
void dfs(ll num,ll sum,ll l,ll r){
	if(num>len)return;
	if(num==0){
		ans=max(ans,sum);
		for(ll i=l;i<=r;i++){
			if(!vis[i]){
				vis[i]=1;
				dfs(num+1,sum+1,pi[i],pj[i]);
				vis[i]=0;
			}
		}
	}else{
		ans=max(ans,sum);
		for(ll i=l;i<=r;i++){
			if(!vis[i]){
				if(pi[i]>l or pj[i]<r)continue;
				vis[i]=1;
				dfs(num+1,sum+1,min(pi[i],l),max(pj[i],r));
				vis[i]=0;
			}
		}	
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(ll j=1;j<=i;j++){
			b[j][i]=b[j][i-1] xor a[i];
		}
		b[i][i]=a[i];
		b[1][i]=b[1][i-1] xor a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(b[i][j]==k){
				len++;
				pi[len]=i,pj[len]=j;
			}
		}
	}
	dfs(0,0,1,len);
	cout<<min(ans,len);
	return 0;
}
