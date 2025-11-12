#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n;
int a[N];
int dfs(int len,int i,int num)
{
	if(len==1)
	{
		if(num>a[i]*2)
			return 1;
		return 0;
	}
	int ans=0;
	for(int j=i+1;j<=n;j++)
		ans+=dfs(len-1,j,num+a[j]);
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int len=3;len<=n;len++)
		for(int i=1;i<=n-len+1;i++)
			ans+=dfs(len,i,a[i]);
	cout<<ans<<endl; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

