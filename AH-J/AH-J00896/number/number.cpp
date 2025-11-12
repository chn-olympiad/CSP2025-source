#include<bits/stdc++.h>
using namespace std;

string s;
//vector<int> num;
int m,num[1000005];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s)
	{
		if(i>='0' && i<='9')
		{
			m++;
			//num.push_back(i-'0');
			num[m]=i-'0';
		}
	}
	sort(num+1, num+1+m, greater<int>());
	for(int i=1;i<=m;i++)
	{
		cout<<num[i];
	}
	return 0;
}
