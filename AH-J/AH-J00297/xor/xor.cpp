#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N],b[N];
bool pd1=true,pd2=true;
int cnt1,cnt2;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	b[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0) 
		{
			pd1=false;
			if(a[i]!=1)
			{
				pd2=false;
			}
		} 
		if(a[i]==0) cnt1++;
		if(a[i]==1) cnt2++;
		b[i]=a[i]^b[i-1];
	}
	if(k==0&&pd1==false&&pd2==true)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1&&a[i+1]==1) ans++,i+=2; 
		}
		cout<<ans+cnt1;
		return 0;
	} 
	if(k==0&&pd1==true) 
	{
		cout<<n;
		return 0;
	}
	if(k==1&&pd1==true) 
	{
		cout<<0;
		return 0;
	}
	if(k==1&&pd1==false&&pd2==true) 
	{
		cout<<cnt2;
		return 0;
	}
	
	return 0;
}
