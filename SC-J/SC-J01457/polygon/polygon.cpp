#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[5005][2];
long long n,sum=0;
void dfs(long long mgs,long long cd,long long djg,long long zdz,long long fz)
{
	sum%=998244353; 
	if (djg-1>n) return;
	if (mgs>=3&&cd>(zdz*2)&&fz==1)
	{
		sum++;
	}
//	cout<<mgs<<" "<<cd<<" "<<djg<<" "<<zdz<<" || "<<sum<<"\n";
	
	if (b[djg][1]==0)
	{
		b[djg][1]=1;
		dfs(mgs+1,cd+a[djg],djg+1,max(zdz,a[djg]),1);
		b[djg][1]=0;
	}
	if (b[djg][2]==0)
	{
		b[djg][2]=1;
		dfs(mgs,cd,djg+1,zdz,0);
		b[djg][2]=0;
	}
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0,0,1,-1,0);
	sum%=998244353; 
	cout<<sum;
	return 0;
}