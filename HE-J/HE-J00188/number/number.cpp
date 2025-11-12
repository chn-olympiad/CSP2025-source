#include<bits/stdc++.h>
using namespace std;
string s;
int sum;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=9;i++)
	{
		if(s[i]>sum)
		sum++;
	}
	cout<<sum;
	return 0;
}
