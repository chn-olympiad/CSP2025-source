#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, q, sp[N],_1[N],_2[N];
map<string, int> mp;
string s[N][3];

void solve1()
{
	int ans = 0;
	string t1, t2;
	cin >> t1 >> t2;
	string x, y;
	for (int i = 0; i < t1.size(); i++)
	{
		y = "";
//			cout << "i: " << i << "\n";
		for (int j = i; j < t1.size(); j++)
		{
			y.push_back(t1[j]);
//				cout << x<<" "<< y << "\n";
			if (mp.find(y) != mp.end())
			{
				string tmp = x + s[mp[y]][2];
//					cout << "on: " << mp[y]<< " tmp: "<<tmp<<"\n";
				for (int k = j + 1; k < t1.size(); k++) tmp.push_back(t1[k]);
				if (tmp == t2) ans++;
			}
		}
		x.push_back(t1[i]);
	}
	cout << ans << "\n";
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][1] >> s[i][2];
		mp[s[i][1]] = i;
	}
	if (n>100){
	for (int i = 1; i<=n;i++)
	{
		for (int j= 0;j <s[i][1].size();j++)
		{
			if (s[i][1][j]=='b'){_1[i]=j;break;
			}
		}
		for (int j= 0;j <s[i][2].size();j++)
		{
			if (s[i][2][j]=='b'){_2[i]=j;break;}
		}
		if(_1[i]!=-1&&_2[i]!=-1)sp[i]=_2[i]-_1[i];
	}}
	while (q--)
	{
		if (n <= 100)solve1();
		else
		{
			string t1,t2;
			cin>>t1>>t2;
			int ans=0;
			int a=-1,b=-1;
			for (int j= 0;j <t1.size();j++)
			{
				if (t1[j]=='b'){a=j;break;
				}
			}
			for (int j= 0;j <t2.size();j++)
			{
				if (t2[j]=='b'){b=j;break;}
			}
			for (int i =1;i<=n;i++)
			{
				if(b-a==sp[i])ans++;
			}
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}
