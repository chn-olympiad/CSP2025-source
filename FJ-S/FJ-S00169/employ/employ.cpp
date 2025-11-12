#include<bits/stdc++.h>
#define max_n 505
using namespace std;
int n;
int hd;
int a[max_n];
int hard[max_n];
int ans=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>hd;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	while(hd>=10)
	{
		cnt++;
		hard[cnt]=hd%10;
		hd=hd/10;
	}
	bool p=true;
	for(int i=1;i<=cnt;i++)
	{
		if(hard[i]!=1)
		{
			p=false;
		}
	}
	if(p)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i;
			ans=ans%998244353;
		}
        cout<<ans;
	}
	return 0;
}
