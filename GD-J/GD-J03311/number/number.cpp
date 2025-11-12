#include<bits/stdc++.h>
using namespace std;
long long a[1000005]; 
int main()
{
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int ans,sum=0;
	for(int i=0;i<len;i++)
	{
		ans=s[i];
		if(ans>47 && ans<58)
		{
			a[i+1]=ans-'0';
			if(ans==48)
			{
				sum++;
			}
		}	
	}
	sort(a+1,a+len+1);
//	int cnt;
//	for(int i=1;i<=len;i++)
//	{
//		if(a[i+1]<a[i])
//		{
//			cnt=a[i];
//			a[i]=a[i+1];
//			a[i+1]=cnt;
//		}
//	}
//	for(int i=1;i<=len;i++)
//	{
//		for(int j=1;j<=len;j++)
//		{
//			
//			if(a[i]>=0)
//			{
//				cout<<a[i];
//			}
//			if(a[i]==0 && sum!=0)
//			{
//				cout<<
//			}
//		}	
//	}

	for(int i=len;i>=1;i--)
	{
		if(a[i]!=0)
		{
			cout<<a[i];
		}
		
//		if(a[i]==0 && sum!=0)
//		{
//			cout<<a[i];
//			sum--
//		}
	}
	for(int i=1;i<=sum;i++)
	{
		if(a[i]==0)
		{
			cout<<a[i];
		}
	}
	return 0;
} 
