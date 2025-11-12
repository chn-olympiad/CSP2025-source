#include<bits/stdc++.h>
using namespace std;
long long a[5][100005];
long long t,n,ans=0,b[5];

void dfs(int step,long long sum)
{
	if(step>n){
		ans=max(ans,sum);
		return;
	} 
	for(int i=1;i<=3;i++){
		b[i]++;
		if(b[i]<=n/2){		
			dfs(step+1,sum+a[i][step]);
		}
		b[i]--;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		bool flag=true;
		cin>>n;
		for(int j=1;j<=n;j++) 
		{
			cin>>a[1][j]>>a[2][j]>>a[3][j];
			if(a[2][j] || a[3][j]) flag = false;
		}
		ans=0;
		if(flag) {
			sort(a[1]+1,a[1]+n+1);
			for(int j=n;j>=n-n/2+1;j--)
			{
				ans+=a[1][j];
			}
			cout<<ans<<'\n';
		}
		else {
			dfs(1,0);
			cout<<ans<<'\n';
		}
	}	
} 
