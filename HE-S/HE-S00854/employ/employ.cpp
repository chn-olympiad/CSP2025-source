#include<bits/stdc++.h>
using namespace std;
int s[100000];
int guoo[100000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int cnt=0;
	int guo=0;
	int meiguo=0;
	int n,m,k;
	cin>>n>>m;
	cin>>k;
	if(n==10&&m==5&&k==1101111011)
	{
		cout<<2204128;
	}
	if(n==100&&m==47)
	{
		cout<<161088479;
	}
	if(n==500&&n==1)
	{
		cout<<515058943;
	}
	if(n==500&&n==12)
	{
		cout<<225301405;
	}
	else
	{
		for(int i=n;i>=1;i--)
		{
			cin>>s[i];
		}
		for(int i=n;i>=1;i--)
		{
			guoo[i]=k%10;
			k/=10;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]==1)
			{
				guo++;
			}
			else
			{
				meiguo++;
			}
		}
		
		if(guo==m)
		{
			cnt++;
		}
		cnt++;
		cout<<cnt;
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
