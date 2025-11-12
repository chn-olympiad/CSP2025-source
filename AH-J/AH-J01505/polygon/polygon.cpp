#include<bits/stdc++.h>
using namespace std;
int n,a[10005],ans;
void dfs(int idx,int cnt,int mx,int len){
	if(idx>n){
		return ;
	}
	for(int i=idx+1;i<=n;i++){
		//cout<<idx<<" "<<len+a[i]<<" "<<max(a[i]*2,mx)<<"\n";
		if(len+a[i]>max(mx,a[i]*2)) {
			 ans++;
			//cout<<len+a[i]<<" "<<max(a[i]*2,mx)<<"\n";
			dfs(i,cnt+1,max(mx,a[i]*2),len+a[i]);
			//cout<<ans<<'\n'<<'\n';
		}
		else dfs(i,cnt+1,mx,len+a[i]);
	}
}
int main(){
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i]*2,a[i]);
	}
	cout<<ans;
	return 0;
}
