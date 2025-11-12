#include<bits/stdc++.h>
using namespace std;
int n, q, s, k, v1[10000], v2[10000], f;
string r1[200001], r2[200001], s1, s2;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> r1[i] >> r2[i];
		for(char c = 'a'; c <= 'z'; c++)
		{
			if(r1[i].find(c) != string::npos)
				v1[(int)c]++;
			if(r2[i].find(c) != string::npos)
				v2[(int)c]++;
		}
	}
	for(int i = 1; i <= q; i++)
	{
		cin >> s1 >> s2, k = s1.length(), s = 0, f = 1;
		string t1 = s1, t2 = s2;
		if(s2.length() != s1.length())
		{
			cout << "0\n";
			continue;
		}
		for(int j = 0; j < k && f; j++)
		{
			if(s1[j] == s2[j])
				s1.erase(j, 1), s2.erase(j, 1), j--, k--;
			else
				if(!v1[(int)s1[j]] || !v2[(int)s2[j]])
					cout << "0\n", f = 0;
		}
		if(!f)
			continue;
		for(int j = 1; j <= n; j++)
			if(r1[j].find(s1) != string::npos && r2[j].find(s2) != string::npos && t1.find(r1[j]) != string::npos && t2.find(r2[j]) != string::npos)
				s++;
		cout << s << '\n';
	}
	
	
	
	
	
	
	return 0;
} 
