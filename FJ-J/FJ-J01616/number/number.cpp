#include <bits/stdc++.h>
using namespace std;
string s;
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s;
	vector<int > numbers;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			numbers.push_back(s[i] - '0');
		}
	}
	sort(numbers.begin(),numbers.end(),cmp);
	for(int number : numbers)
	{
		cout<<number;
	}
	return 0;	
} 
