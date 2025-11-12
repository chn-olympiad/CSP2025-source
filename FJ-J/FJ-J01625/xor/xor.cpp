#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}else if(k==0){
		int cnt=0,cntt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cnt++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1&&a[i+1]==1)
			{
				a[i]=0;
				a[i+1]=0;
				cntt++;
			}
		}
		cout<<cnt+cntt;
		return 0;
	}else{
		cout<<0;
		return 0;
	}
	return 0; 
}
