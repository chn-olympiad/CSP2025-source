#include<bits/stdc++.h>
using namespace std;
int n;
int a[114514];
int sum[114514];
int js=0; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		
		cin>>a[i];
		js=max(js,a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	if(n==3)
	{
		if(sum[3]>2*js) 
		cout<<'1';
		else
		cout<<'0';
		
		return 0;
	}
	while(n--)
	{
		cout<<"½­¼ÑÐÀ£¬ÎÒÏ²»¶Äã\n"; 
	}
	return 0;	
} 
