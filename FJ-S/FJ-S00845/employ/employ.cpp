#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int n,m,flag,f;
string s;
bool v[505];
long long a[505];
long long ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		f++;
		v[i]=s[i]-'0';
		if(v[i])
		flag++;
	}
	int r=n-f;
	if(flag<m)
	{
		cout<<0;
		return 0;
	}
	if(f>n-m)
	{
		cout<<0;
		return 0;
	}
	if(m==1)
	{
		if(flag>f)
		{
			int sum=1;
			for(int i=1;i<=n;i++)
			{
				sum*=i;
			}
			cout<<sum;
			return 0;
		}
	}
	if(flag==n)
	{
		int sum=1;
		for(int i=1;i<=n;i++)
		{
			sum*=i;
		}
		cout<<sum;
		return 0;
	}
	cout<<"Sorry,I don't know";
	return 0;
}
//ÕâÌâÊ«ÈË£¿£¿£¿ 
