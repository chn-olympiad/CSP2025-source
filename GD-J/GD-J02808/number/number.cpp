#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int b[11][4000],d[11],d1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1);
	for(int i=1;i<=1000000;i++)
	{
		d1=1;
		if(a[i]>='0'&&a[i]<='9')
		{
			b[a[i]-'0'][1]++;
			while(b[a[i]-'0'][d1]>10000)
			{
				b[a[i]-'0'][d1]=0;
				b[a[i]-'0'][d1+1]++;
				d1++;
				if(d[a[i]-'0']<d1) d[a[i]-'0']=d1;
			}
		}
		if(a[i]==' ') break;
	}
	for(int i=9;i>=0;i--)
	{
		while(b[i][1]!=0)
		{
			d1=1;
			printf("%d",i);
			b[i][1]--;
			if(b[i][1]==0)
			{
				while(d1<d[i])
				{
					d1++;
					if(b[i][d1]>0)
					{
						while(d1>1)
						{
							b[i][d1]--;
							b[i][d1-1]+=10000;
							d1--;
						}
					}
				}
			}
			if(b[i][d[i]]==0) d[i]--;
		}
	}
}
