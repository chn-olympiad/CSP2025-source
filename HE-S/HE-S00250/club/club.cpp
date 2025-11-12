#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],b,ans,k[100005];
int dfs(int num,int sum,int b1,int b2,int b3)
{
	if(num==n+1)
	{
		ans=max(ans,sum);
		return 0;
	}
	if(b1>0){
		dfs(num+1,sum+a[num][1],b1-1,b2,b3);
	}
	if(b2>0){
		dfs(num+1,sum+a[num][2],b1,b2-1,b3);
	}
	if(b3>0){
		dfs(num+1,sum+a[num][3],b1,b2,b3-1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		memset(k,0,sizeof k);
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			k[i]=a[i][1]-a[i][2];	
		}
		sort(k+1,k+n+1);
		if(n<=30){
			b=n/2;
			dfs(1,0,b,b,b);
			cout<<ans<<endl;
			ans=0;
		}
		else{
			b=n/2;
			for(int i=1;i<=n;i++){
				ans+=a[i][2];
			}
			for(int i=1;i<=b;i++)
			{
				ans+=k[i];
			}
			cout<<ans<<endl;
			ans=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
