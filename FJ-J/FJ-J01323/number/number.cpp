//number
#include<bits/stdc++.h>
using namespace std;
int as=0;
short a[1000006];
char c[1000006];
int ns[10]={0,0,0,0,0,0,0,0,0,0};
int main() 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&c);
	int z=0;
	while((c[z]>='a'&&c[z]<='z')||(c[z]>='0'&&c[z]<='9'))
	{
		if(c[z]>='0'&&c[z]<='9')
		{
			ns[c[z]-'0']++;
		}
		z++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=ns[i];j++)printf("%d",i);
	}
	return 0;
}
