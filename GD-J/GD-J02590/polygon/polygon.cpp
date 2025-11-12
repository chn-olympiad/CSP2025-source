#include<bits/stdc++.h>
using namespace std;
long long n,cnt,a[5000];
bool b[5000];
void dfs(long long ma,int su,int si,int xa)
{
	for(int i=0;i<n;i++)
	{
		if(!b[i]&&i>=xa)
		{
			if(si>=3&&(max(ma,a[i]))*2<su+a[i])
			{
				cnt++;
				cnt=cnt%998244353;
			}
			b[i]=1;
			dfs(max(ma,a[i]),su+a[i],si+1,i);
			b[i]=0;
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	dfs(0,0,2,0);
	cout<<cnt;
	return 0;
}
