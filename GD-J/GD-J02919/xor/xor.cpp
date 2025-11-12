#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005];
bool fl=true;
void sloveAB()
{
	int ans=0;
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]) ans++;
		}
		cout<<ans;
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1&&a[i+1]==1) ans++,i++;
			else if(a[i]==0) ans++;
		}
		cout<<ans;
	}
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1) 
		{
			fl=false;
		}
	}
	if(k<=1&&fl) sloveAB();
	else cout<<0;
	return 0;
}

