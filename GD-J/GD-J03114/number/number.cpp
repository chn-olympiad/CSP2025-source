#include<bits/stdc++.h>
using namespace std;

char a[1000010];
char num[15]="0123456789";
int dis[15];
bool check=true;
int main()
{
	memset(dis,0,sizeof(dis));
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(auto i:a)
	{
		for(int j=0;j<10;j++)
		{
			if(i==num[j])
			{
				if(i!='0') check=false;
				dis[j]++;
			}

		}
	}
	if(check)
	{
		cout<<0;
	}
	else
	{
		for(int i=9;i>=0;i--)
		{
			for(int j=1;j<=dis[i];j++)
			{
				cout<<i;
			}
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
