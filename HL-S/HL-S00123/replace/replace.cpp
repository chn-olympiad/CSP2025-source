#include<bits/stdc++.h>
using namespace std;
struct eryuan
{
	string s1,s2;
} a[200010];
struct que
{
	string t1,t2;
} b[200010];
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
		cin >> a[i].s1 >> a[i].s2;
	while(q--)
	{
		string t1,t2; int ans = 0;
		cin >> t1 >> t2;
		if(t1.size() != t2.size())
		{
			cout << 0 << endl;
			continue;
		}
		for(int i = 1;i <= n;i++)
		{
			int len = a[i].s1.size();
			if(len == t1.size())
			{
				if(a[i].s1 == t1 && a[i].s2 == t2) ans++;
				continue;
			}
			for(int j = 0;j < t1.size()-len+1;j++)
			{
				string nowy = t1.substr(j,len);
				if(nowy != a[i].s1) continue; 
				string nowx = t1.substr(0,j);
				string nowz = t1.substr(j+len,t1.size()-1);
//				cout << nowx << ' ' << nowy << " " << nowz << endl;
				string now = nowx + a[i].s2 + nowz;
				if(now == t2) ans++;
//				cout << now << endl;
			}
		}
		cout << ans << "\n";
	}
		
	
	return 0;
}

