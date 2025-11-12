#include<bits/stdc++.h>

using namespace std;


int n,q;
long long ans=0;
int pl=0,pr=0;
string s1,s2;
set< pair<string,string> > c_s;

void find_dif()
{
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]==s2[i])
			continue;
		else
		{
			pl=i;
			break;
		}
	}
	for(int i=pl+1;i<s1.size();i++)
	{
		if(s1[i]==s2[i])
			continue;
		else
			pr=i;
	}
	if(!pr)
	{
		pr=pl;
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> s1 >> s2;
		c_s.insert(make_pair(s1,s2));
	}
	while(q--)
	{
		cin >> s1 >> s2;
		if(s1.size()!=s2.size())
		{
			cout << 0 << endl;
			continue;
		}
		find_dif();//记得初始化 pl从0开始
		for(int l=0;l<=pl;l++)
		{
			for(int r=s1.size()-1;r>=pr;r--)
			{
				int len= r-l+1;
				string ts1,ts2;
				ts1 = s1.substr(l,len);
				ts2 = s2.substr(l,len);
				if(c_s.count(make_pair(ts1,ts2)))
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
		pl=0;
		pr=0;
		ans=0;
	}
	return 0;
}
