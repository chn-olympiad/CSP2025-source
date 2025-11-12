#include <bits/stdc++.h>
using namespace std;
long long sum=0,pos=1,ans=-1e9,m,maxn,da[1000005],a[1000005]={999};
string s;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	if(s.size()==1)
	{
		cout <<s;
		return 0;
	}
	bool flag=true;
	for(int i=0;i<s.size();i++)
	{
		if(!(s[i]=='0' || s[i]=='1'|| s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'))
		{
			flag=false;
		}
	}
	if(flag)
	{
		cout <<s;
		return 0;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='a' && s[i]<='z')
		{
			continue;
		}
		else
		{
			if(s[i]=='0')
			{
				a[pos]=0;
				sum+=1;
			}
			else if(s[i]=='1')
			{
				a[pos]=1;
				sum+=1;
			}
			else if(s[i]=='2')
			{
				a[pos]=2;
				sum+=1;
			}
			else if(s[i]=='3')
			{
				a[pos]=3;
				sum+=1;
			}
			else if(s[i]=='4')
			{
				a[pos]=4;
				sum+=1;
			}
			else if(s[i]=='5')
			{
				a[pos]=5;
				sum+=1;
			}
			else if(s[i]=='6')
			{
				a[pos]=6;
				sum+=1;
			}
			else if(s[i]=='7')
			{
				a[pos]=7;
				sum+=1;
			}
			else if(s[i]=='8')
			{
				a[pos]=8;
				sum+=1;
			}
			else if(s[i]=='9')
			{
				a[pos]=9;
				sum+=1;
			}
			pos+=1;
		}
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++)
	{
		cout <<a[i];
	}
	return 0;
}
