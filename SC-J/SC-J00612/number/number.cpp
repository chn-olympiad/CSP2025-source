#include<bits/stdc++.h>
using namespace std;

priority_queue<string, vector<string>, less<string> > p; 

int main()
{

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int j = 0;
	string a;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s.substr(i, 1) == "0" || s.substr(i, 1) == "1" || s.substr(i, 1) == "2" || s.substr(i, 1) == "3" || s.substr(i, 1) == "4" || s.substr(i, 1) == "5" || s.substr(i, 1) == "6" || s.substr(i, 1) == "7" || s.substr(i, 1) == "8" || s.substr(i, 1) == "9")
		{
			a = s.substr(i, 1);
			p.push(a);
			j++;
		}
	}
	for(int i = 0; i < j; i++)
	{
		cout << p.top();
		p.pop();
	}

}