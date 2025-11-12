# include <bits/stdc++.h>

using namespace std;

bool cmp(int x, int y)
{
	return x > y;
}

bool cmpl(int x, int y)
{
	return x < y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	
	freopen("seat.out", "w", stdout);
	
	int n, m;
	
	cin >> n >> m; 
	
	vector<int> s(n * m);
	
	for(int i = 0; i < n * m; i++)
	{
		cin >> s[i];
	}
	
	int Rscore = s[0];
	
	sort(s.begin(), s.end(), cmp); 
	
	vector<vector<int>> t(n, vector<int>(m, 0));
	
	int pos = 0;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			t[i][j] = s[pos];
			
			pos++;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(i % 2 != 0)
			{
				sort(t[i].begin(), t[i].end(), cmpl);
			}
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(t[i][j] == Rscore)
			{
				cout << i + 1 << ' ' << j + 1; 
			}
		}
	}
	
	return 0;
}
