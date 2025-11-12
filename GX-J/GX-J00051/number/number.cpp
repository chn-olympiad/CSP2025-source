#include<bits/stdc++.h>
using namespace std;
char a[10005];
char sz[1005];
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int i=0,o=0;
char jhz;
cin>>a;
while((a[i]>48 && a[i]<59) || (a[i]>65 && a[i]<91) || (a[i]>96 && a[i]<123))
{if(a[i]>48 && a[i]<59)
	{
		sz[o]=a[i];
		o=o+1;}
	i++;
	}
for(int j=0;j<o;j++)
{for(int l=j+1;l<o;l++)
{if(sz[j]<sz[l])
	{jhz=sz[j];
	sz[j]=sz[l];
	sz[l]=jhz;}}
}
for(int j=0;j<o;j++)
{cout<<sz[j];}
	return 0;
}
