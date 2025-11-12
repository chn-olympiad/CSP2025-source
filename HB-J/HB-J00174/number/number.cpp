#include<bits/stdc++.h>
using namespace std;
int a[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string b;
	cin>>b;
	int i=0;
	while(b[i]!='\0')
	{
		for(int k=0;k<=9;k++)
		{
			if(b[i]>='0'&&b[i]<='9') 
			{
				a[b[i]-'0']++;
				break;
			}
		}
		i++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int k=0;k<=a[i];k++)
		{
			cout<<i;
		}
	}
	return 0;
}
