#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	vector<string> s1, s2, s3, s4;
	unordered_map<string, vector<int>> m;
	for (int i = 1; i <= n; ++ i)
	{
		string ss1, ss2, ss666, ss777;
		cin>>ss1>>ss2;
		int sz = ss1.size();
		int j = 0, l = sz - 1;
		for (; j < sz; ++ j)
		{
			if (ss1[j] != ss2[j])
				break;
		}
		for (; l >= 0; l --)
		{
			if (ss1[l] != ss2[l])
				break;
		}
		ss666 = ss1.substr(j, l - j + 1);
		ss777 = ss2.substr(j, l - j + 1);
		m[ss666].push_back(i - 1);
		s1.push_back(ss666);
		s2.push_back(ss777);
		s3.push_back(ss1.substr(0, j));
		s4.push_back(ss1.substr(l + 1, sz - 1 - l));
	}
	for (int i = 1; i <= q; ++ i)
	{
		string t1, t2, tt666;
		cin>>t1>>t2;
		int sz = t1.size(), sssz = t2.size();
		if (sz != sssz)
		{
			printf("0\n");
			continue;
		}
		int j = 0, l = sz - 1, sum = 0;
		for (; j < sz; ++ j)
		{
			if (t1[j] != t2[j])
				break;
		}
		for (; l >= 0; l --)
		{
			if (t1[l] != t2[l])
				break;
		}
		tt666 = t1.substr(j, l - j + 1);
		vector<int> v;
		if (m.count(tt666))
		{
			v = m[tt666];
		}
		for (auto x : v)
		{
			if (s2[x] != t2.substr(j, l - j + 1))
				continue;
			int a = s3[x].size(), b = s4[x].size();
			if (t1.substr(j - a, a) == s3[x] && t1.substr(l + 1, b) == s4[x])
				sum ++;
		}
		printf("%d\n", sum);
	}
	return 0;
} 
