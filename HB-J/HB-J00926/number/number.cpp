#include<bits/stdc++.h>
using namespace std;
string b;
int c[1000005];
int d[1000005];
int flag[1000005];
int high;
int ans=0;
int cnt;
int main()
{
	//a shi 96 zshi 121
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(int i=0;i<b.length();i++)//pan duan zifu
	{
		if(b[i]>='a' and b[i]<='z')
		{
			flag[i]=1;
			cnt++;
			
		}
		if(b[i]>='A' and b[i]<='Z')
		{
			flag[i]=1;
			cnt++;
			
		}
		if(b[i]==' ')
		{
			flag[i]=1;
			cnt++;
			
		}
	}
	int j=0;
	for(int i=0;i<b.length();i++)//ti chu zimu
	{
		if(flag[i]==0)
		{
			c[j]=b[i]-'0';
			j+=1;
		}
	}
	for(int j=0;j<b.length()-cnt;j++)
	{
		for(int i=0;i<b.length()-cnt;i++)
		{
			if(c[i]>=ans)
			{
				ans=c[i];
				high=i;
		    }
		}
		d[j]=ans;
		c[high]=0;
		ans=0;
		high=0;
	}
	for(int i=0;i<b.length()-cnt;i++)
	{
		cout<<d[i];
	}
	return 0;
}
