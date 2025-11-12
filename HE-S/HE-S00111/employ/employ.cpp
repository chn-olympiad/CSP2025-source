#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a,b;
	cin>>a>>b;
	string s;
	cin>>s;
	int sum = 0;
	for(int i = 1;i<=size();i++)
	{
		if(s[i]=='1')
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
 } 
