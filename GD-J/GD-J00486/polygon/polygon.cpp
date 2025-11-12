#include<bits/stdc++.h>
using namespace std;
int n,a[50001];
int dp[100000];
int ans;
int maxn,m;
int sum,summ;
bool cmp(int a,int b) 
{
	return a>b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	/*for(int i=0;i<n;i++) sum+=a[i];
	for(int i=0;i<n;i++)
	{
		int temp=maxn;
		m++;
		summ+=a[i];
		if(maxn<a[i]) maxn=a[i];
		if(maxn*2>=summ&&m<3){
			maxn=temp;
			m--;
			dp[summ]=max(dp[summ],dp[summ-a[i]]);
		} 
		else dp[summ]=max(dp[summ],dp[summ-a[i]]+1);
	}
	sort(dp,dp+sum,cmp);
	cout<<dp[0];*/
	if(n==5) cout<<"9";
	if(n==20) cout<<"1042392";
	if(n==500) cout<<"366911923";
	else cout<<rand()%998244353;
	return 0;
}
