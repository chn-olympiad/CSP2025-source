#include<bits/stdc++.h>
using namespace std;
int a[5005];
bool k[5005];
int n;
int cnt;
void dfs(int x)
{
	if(x==n)
	{
		int s=0,sum=0,m;
		for(int l=0;l<n;l++)
		{
			if(k[l])
			{
				s++;
				sum+=a[l];
				m=l;
			}
		}
		if(s>=3&&sum>a[m]*2)
		{
			cnt++;
		}
	
		return;
	}
	for(int i=x;i<n;i++)
	{
		if(!k[i])
		{
			k[i]=true;
			dfs(i+1);
			k[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	dfs(0);
	cout<<cnt;
	return 0;
}
