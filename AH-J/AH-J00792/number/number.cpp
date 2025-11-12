#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >>s;
	for(int i=1;i<s;i++)
	{
		int max;
		cin >> s;
		for(int i=1;i<s;i++)
		{
			if(s>max)
			{
				max=s;
			}
			else if(s<max)
			{
				max=max;
			}
			else if(s==max)
			{
				max=s;
			}
	}
	cout<<max;
	return 0;
}
