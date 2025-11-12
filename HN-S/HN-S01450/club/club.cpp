#include<bits/stdc++.h>
using namespace std;
int a[100010][5],dp[50010][3],b[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<=50010;i++)a[i][1]=a[i][2]=a[i][3]=0;
		int n,ans=0,se=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
			if(a[i][2]==0&&a[i][3]==0)se++; 
		}
		if(se==n){
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+n+1);
			int sum=0;
			for(int i=n;i>=n/2+1;i--)sum+=b[i];
			cout<<sum<<endl;
			continue;
		}	
		if(n==2){
			int maxn=0;
			for(int i=1;i<=3;i++)
				for(int j=1;j<=3;j++)
					if(i!=j)
						maxn=max(maxn,a[1][i]+a[2][j]);
			cout<<maxn<<endl;
			continue;
		}	
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				for(int k=i;k>=1;k--)
					dp[k][j]=max(dp[k][j],dp[k-1][j]+a[i][j]);
		for(int i=1;i<=n/2;i++)
			for(int j=1;j<=n-i;j++)
				ans=max(ans,dp[i][1]+dp[j][2]+dp[n-i-j][3]);
		cout<<ans<<endl;
	}
	return 0;
} 
