#include <bits/stdc++.h>
using namespace std;

string t;
int num[1000005];
int nums;

int cmp(const int &a,const int &b)
{
	if (a > b) return 1;
	else return 0;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> t;
	int tnum = t.size();
	for (int i = 0;i < tnum;i++)
	{
		if (t[i] >= '0' && t[i] <= '9')
		{
			num[nums] = t[i] - '0';
			nums ++;
		}
	}
	sort(num,num + nums,cmp);
	for (int i = 0;i < nums;i++)
		cout << num[i];
	return 0;
}
