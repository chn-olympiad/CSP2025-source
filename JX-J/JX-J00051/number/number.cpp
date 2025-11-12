#include<bits/stdc++.h>
using namespace std;
string a;
long long  cont[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			cont[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(cont[i]>0)
		{
			while(cont[i]--)
			{
				cout<<i;
			}
		}
	}
	cout<<endl;
	return 0;
}
