#include<bits/stdc++.h>
using namespace std;
char a[1000005],b[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int o=0;
	int y=strlen(a);
	for(int i=0;i<y;i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			b[o]=a[i];
			o++;
		}
	}
	for(int i=0;i<o;i++)
	{
		for(int j=i+1;j<o;j++)
		{
			if(b[i]<b[j])
			{
				swap(b[i],b[j]);
			}
		}
	}
	for(int i=0;i<o;i++)
	{
		cout<<b[i];
	}
	return 0;
}
