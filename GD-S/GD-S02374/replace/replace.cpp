#include <bits/stdc++.h>
using namespace std;

string s1[10005], s2[10005];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> s1[i] >> s2[i];
	while(m--)
	{
		int cnt = 0;
		string t1, t2;
		cin >> t1 >> t2;
		for(int j = 1; j <= n; j++)
		{ 
			int len = s1[j].size();
			for(int i = 0; i <= t1.size()-len; i++)
			{
				if(t1.substr(i,len)==s1[j]){
					string x = t1.substr(0,i);
					x=x+s1[j];//+t1.substr(i+len,t1.size()-i-len+1);
					cout << x << "\n";
					//if(x==t2)cnt++;
					
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
