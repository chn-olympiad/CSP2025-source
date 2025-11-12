#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n,k;
int a[500005];
int sum[500005];
pair<int,int>qj[500005];
int len;
int vis[500005];
int d[500005];
void dfs(int step,int lst){
	ans=max(ans,step-1);
	for(int i=lst+1;i<=len;i++){
		if(qj[i].first>qj[d[step-1]].second){
			d[step]=i;
			dfs(step+1,i);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				qj[++len]={i,j};
			}
		}
	}
	dfs(1,0);
	cout<<ans<<"\n"; 
	return 0;
}
