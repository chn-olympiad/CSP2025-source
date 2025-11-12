#include<bits/stdc++.h>
using namespace std;

int number[1000010];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin >> str;
	//cerr << str << endl;
	long long n=str.size();
	//cerr << n << endl;
	int p=0;
	for(int i=0;i<n;i++)
	{
		if('0'<=str[i] && str[i]<='9')
		{
			//cerr << str[i]-'0';
			number[p]=str[i]-'0';
			p++;
		}
	}
	//cerr << endl;
	sort(number,number+p);
	for(int i=p-1;i>=0;i--)
	{
		cout << number[i];
	}
	return 0;
}
