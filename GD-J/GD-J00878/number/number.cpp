#include<bits/stdc++.h>
using namespace std;
int b[105];
char a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);

	for(int i=0;a[i]!='\0';i++)
	{
		int p=int(a[i])-int('0');
		if(p>=0&&p<=9) b[p]++;

	}
	for(int i=9;i>=0;i--)
	{
		if(b[i]!=0)
		{
			while(b[i]!=0)
			{
				cout<<i;
				b[i]--; 
			}
		}
	}
	return 0;
 } 
