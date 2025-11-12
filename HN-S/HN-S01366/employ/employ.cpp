#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000],b[1000],c[1000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m,t=0;
	cin>>n>>m;
	m=n-m;//m为最多不要多少人 
	
	cin>>s;
	for(int i=0,j=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			b[i]=999999;
			j++;
			t++;	
		} 
		else
		{
			b[i]=j;
		}
	} 
	
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	sort(a,a+n);
	if(t<=m)
	{
		cout<< 0 <<endl;
		return 0; 
	} 
	
	long long ans=0; 
	
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>=0;j--)	
		{
			if(a[i]<=s[j])
			{
				c[j]++;
			}
		}
	} 
	


	return 0;	
} 
