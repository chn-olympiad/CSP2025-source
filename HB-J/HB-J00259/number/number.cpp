#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000005];
	int a[1000005];
	cin>>s;
	int i=0;
	int j=0;
	while(s[i]!=' ')
	{
		if(int(s[i])>=48&&int(s[i])<=57)
		{
			a[j]=int(s[i])-48;
			j++;
		}
		i++;
	}
	
	sort(a,a+j-1);
	
	for(int k=j-2;k>=0;k--)
	{
		cout<<a[k];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
