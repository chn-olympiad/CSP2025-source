#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out ","w",stdout);
	char a[1000005];
	int b[10],i=0;
	cin>>a;
	while(a[i])
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[a[i]-'0']++;
		}
		i++;
	}
	for(int l=9;l>=0;l--)
	{
		//cout<<b[l];
		if(b[l]!=0)for(int v=1;v<=b[l];v++)cout<<l;
	}
	return 0;
 } 
