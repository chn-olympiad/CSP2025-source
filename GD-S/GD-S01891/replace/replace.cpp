#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;

int n, q;

struct node
{
	string a, b;
}arr[N];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i].a >> arr[i].b;
	}
	
	while(q--)
	{
		string s1, s2, s = "", ss = "";
		bool flag1 = 1, flag2 = 1;
		cin >> s1 >> s2;
		
		if(s1.size() <= 2) 
		{
			cout << 0 << endl;
			continue;
		}
		
		for(int i = 0; i <= s1.size()-1; i++)
		{
			if(flag1 && s1[i] == s2[i]) continue;
			else if(s1[i] != s2[i])
			{
				flag1 = 0;
				s.push_back(s1[i]);
				ss.push_back(s2[i]);
			}
			else if(!flag1 && s1[i] == s2[i]) break;
		}
		
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(s == arr[i].a && ss == arr[i].b)
			{
				ans++;
			}
			else 
			{
				int x = 0, y = 0;
				bool flagg = 0;
				for(int j = 0; j <= arr[i].a.size()-1; j++)
				{
					if(arr[i].a[j] == s[x] && arr[i].b[j] == ss[x])
					{
						x++;
					}
					else if(arr[i].a[j] == arr[i].b[j])
					{
						x = 0;
					}
					else
					{
						flagg = 0;
						break;
					}
					
					if(x == s.size()-1) flagg = 1;
				}
				
				if(flagg) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
