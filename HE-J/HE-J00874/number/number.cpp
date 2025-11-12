#include <bits/stdc++.h>
using namespace std;

string s;
int lens, sum_z;
vector <int> v;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	lens = s.length();
	for (int i = 0; i < lens; i++)
	{
		char si = s[i];
		if (si >= '0' && si <= '9')
		{
			si -= '0';
			int sii = (int)(si);
			if (sii == 9)
                cout << sii;
            else
                v.push_back(sii);
		}
	}
	/*
	cout << "-------1-------" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "---1---" << i << endl;
	}
	cout << "-------2-------" << endl;
	*/

	sort(v.begin(), v.end());
	/*
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "---2---" << i << endl;
	}
	*/
	for (int i = v.size(); i >= 0; i--)
	{
		if (v[i] == 0)
		{
			sum_z++;
			//cout << "0++   " << "0okk" << endl;
		}
		else
		{
			cout << v[i];
		}
	}
	//cout << "-------3-------" << endl;
	//cout << sum_z << endl << "3okk" << endl;
	sum_z -= 1;
	if (sum_z != 0)
	{
		for (int i = 1; i <= sum_z; i++)
		{
			cout << '0';
		}
	}
	return 0;
}
