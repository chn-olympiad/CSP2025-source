#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n,k;
int a[N];
bool b[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	
	memset(b,true,sizeof b);
	
	bool isA=true,isB=true;
	int cnt1=0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i] != 1)isA = false;
		if(a[i] != 1 && a[i]!= 0)isB=false;
		if(a[i]==1)cnt1++;
	}
	if(isA)
	{
		cout<<n;
		return 0;
	}
	if(isB)
	{
		if(k==1)cout<<cnt1<<endl;
		else cout<<floor(1.0*cnt1/2);
		return 0;
	}
	
	
	
	
	bool flag=true;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!b[i])continue;
		for(int j=i;j<=n;j++)
		{
			int s=0;
			for(int k=i;k<=j;k++)
			{
				if(b[k])s^=a[k];
				else flag=false;
			}
			if(s==k && flag==true)
			{
				ans++;
				for(int k=i;k<=j;k++)b[k]=false;
			}
			flag=true;
		}
		flag=true;
	}
	
	cout<<ans<<endl;
	
	
	
	return 0;
}
