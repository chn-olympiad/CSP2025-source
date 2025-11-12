#include<bits/stdc++.h>
using namespace std;
int shu[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string number;
	cin>>number;
	int p=number.length();
	for(int i=0;i<=p;i++)
	{
		if(number[i]>='0'&&number[i]<='9')
		{
			shu[number[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=shu[i];j++)
		cout<<i;
	}
	return 0;
}
