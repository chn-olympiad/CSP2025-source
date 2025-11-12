#include<bits/stdc++.h>
using namespace std;

const int MAX_NQ = 2 * 1e5;
const int MAX_L = 5 * 1e6;

int n, q;
vector<vector<string>> s(MAX_NQ, vector<string>(2));
vector<string> t(2);

bool match(string &target, string &mod, int offset)
{
	for (int i = 0; i < mod.length(); i ++)
	{
		if (target[i + offset] != mod[i])
		{
			return false;
		}
	}
	
	return true;
}

string sub_str(string &target, int start, int end)
{
	string result = "";
	
	for (int i = start; i < end; i ++)
	{
		result += target[i]; 
	}
	
	return result;
}

string repl(string &target, int modl, string &to, int offset)
{
	string x = sub_str(target, 0, offset);
	string z = sub_str(target, offset + modl, target.length());
	return x + to + z;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	
	for (int i = 0; i < n; i ++)
	{
		cin >> s[i][0] >> s[i][1];
	}
	
	for (int i = 0; i < q; i ++)
	{
		cin >> t[0] >> t[1];
		
		int cnt = 0;
	
		for (int i = 0; i < n; i ++)
		{
			int ed = t[0].length() - s[i][0].length();
			for (int j = 0; j <= ed; j ++)
			{
				if (match(t[0], s[i][0], j) && repl(t[0], s[i][0].length(), s[i][1], j) == t[1])
				{
					cnt ++;
				}
			}
		}
		
		cout << cnt << endl;
	}
	
	return 0;
}


