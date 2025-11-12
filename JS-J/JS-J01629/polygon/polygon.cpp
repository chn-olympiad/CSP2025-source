#include "bits/stdc++.h"
using namespace std;
int n,ans,a[10000];

void dfs(int u,int sum,int cnt){	
	for(int i=u+1;i<=n;i++){
	//	cout<<i<<" "<<sum+a[i]<<" "<<cnt+1<<" "<<max(maxx,a[i])<<endl;
		dfs(i,sum+a[i],cnt+1);
	}
	if(cnt>=3){
		if(sum>a[u]*2){
			//cout<<"Here is "<<sum<<" "<<cnt<<" "<<maxx<<endl;
			ans++;
			ans%=998244353;
			return ;
		}
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	dfs(i,a[i],1);
	cout<<ans;
	return 0;
}
