#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long n=0,m,p=-1;
	cin>>s;
	m=s.size();
	for(long long i=0;i<m;i++)
	{
		if(s[i]-'0'==0||s[i]-'0'==1||s[i]-'0'==2||s[i]-'0'==3||s[i]-'0'==4||s[i]-'0'==5||s[i]-'0'==6||s[i]-'0'==7||s[i]-'0'==8||s[i]-'0'==9)
		{
			a[i]=s[i]-'0';
			n++;
			if(a[i]>p)
			{
				if(a[i]==0)
				{
					p=99999999;
				}
					p=a[i];
				
			}
			}
			
	}
		sort(a,a+n+1,cmp);
		for(long long i=0;i<n;i++)
	{
		cout<<a[i];
		}
	return 0;
}
