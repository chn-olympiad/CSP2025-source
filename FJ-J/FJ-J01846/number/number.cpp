#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005],sum;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		
		if(s[i] >= '0' && s[i] <= '9')
		{
			num[i+1] = s[i] - '0';
			sum++;
		}
	}
	sort(num+1,num+s.size()+1,cmp);
	for(int i = 1;i <= sum;i++)
	{
		cout << num[i];
	}
	return 0;
}
