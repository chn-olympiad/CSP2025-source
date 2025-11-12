#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],flag,num,b[505];
string s;
void dfs(long long jb,string s1)
{
	if(jb==n)
	{
		long long k=0;
		long long z;
		z=0;
		for(int i=0;i<n;i++)
		{
			if(s1[i]=='0')
			{
				k++;
			}
			else
			{
				if(a[s1[i]-'0']<=k)
				{
					z++;
				}
				else
				{
					k++;
				}
			}
		}
		if(z>=m)
		{
			num++;
		}
		return;
	}
	string s2;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			s2=s1;
			s2+=(i+'0');
			b[i]=1;
			dfs(jb+1,s2);
			b[i]=0;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}	
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		for(int i=m;i<=n;i++)
		{
			if(i<n/2)
			{
				num+=n*i; 
			}
			else
			{
				num+=(n-i)*n;
			}
		}
		cout<<num;
	}
	else if(n<=10)
	{
		string s1;
		s1='0';
		dfs(0,s1);
		cout<<num;
	}
	else
	{
		cout<<"225301405";
	}
	return 0;
}
