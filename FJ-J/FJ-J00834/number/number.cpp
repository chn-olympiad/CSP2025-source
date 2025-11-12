#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string a;
vector<int> v;
bool cmp(int a , int b)
{
	return a > b;
}
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> a;
	for (int i = 0;i < a.size();i++)
	{
		if (a[i] >= '0' and a[i] <= '9')
			v.push_back(a[i] - '0');
	}
	sort(v.begin() , v.end() , cmp);
	for (int i = 0;i < v.size();i++)
	{
		if (i == 0 and v[i] == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		cout << v[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}