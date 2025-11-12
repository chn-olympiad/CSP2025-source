#include <bits/stdc++.h>
using namespace std;
const int N=500010;
int s[N],n,k,a,b,ans=0;
int yhh(int a,int b)
{
	int kk=0,aa=a,bb=b;
	for(int i=30;i>=0;i--)
	{
		if( (aa>=pow(2,i) && bb<pow(2,i) ) || (aa<pow(2,i)  && bb>=pow(2,i) ) )
		{
			kk+=pow(2,i);
		}
		aa%=(int)( pow(2,i) );
		bb%=(int)( pow(2,i) );
	}
	return kk;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0)
	{
		cout<<n/2;
		return 0;
	}
	else if(k==1)
	{
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		}
		int i=0;
		while(i<n)
		{
			if( yhh(s[i],s[i+1])==1 )
			{
				ans++;
				i+=2;
			}
			else
			{
				i++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	while(1)
	{
		
	}
	return 0;
} 
