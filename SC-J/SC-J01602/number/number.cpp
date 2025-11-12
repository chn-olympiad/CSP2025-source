#include<bits/stdc++.h>
using namespace std; 
vector<int> num[10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1001000];
	cin>>a;
	for(int i=0;;i++)
	{
		if(!a[i])
		{
			break;
		}
		int t=a[i]-'0';
		if(t>=0&&t<=9)
		{
			num[t].push_back(t);
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(auto j:num[i])
		{
			cout<<j;
		}
	}
	return 0;
}