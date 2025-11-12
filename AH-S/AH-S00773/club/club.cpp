#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct node{
	int s1,s2,s3;
}a[100005];
void dfs(int x,int sum1,int sum2,int sum3,int sum){
	if(sum1>n/2||sum2>n/2||sum3>n/2)return;
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	dfs(x+1,sum1+1,sum2,sum3,sum+a[x].s1);
	dfs(x+1,sum1,sum2+1,sum3,sum+a[x].s2);
	dfs(x+1,sum1,sum2,sum3+1,sum+a[x].s3);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
		}
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
