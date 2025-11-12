#include<bits/stdc++.h>
using namespace std;
long long a[500005],ans=0,n,s[500005];
void dfs(long long p,long long ma,long long sum,long long cnt){
	if(p>n){
		if(cnt<3){
			return;
		}
		ans++;
		return;
	}
	if(n-p+cnt<3){
		return;
	}
	if(cnt==3&&sum<=ma*2){
		return;
	}
	dfs(p+1,ma,sum,cnt);
	if(sum+a[p]>max(ma,a[p])*2||cnt<3){
		dfs(p+1,max(ma,a[p]),sum+a[p],cnt+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
