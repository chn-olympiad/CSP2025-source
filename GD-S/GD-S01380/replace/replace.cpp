#include<iostream>
#include<map>
using namespace std;
int n;
pair<string,string> mp[200005]; 
string chs;
string s1,s2;
int cnt;
void dfs(int x)
{
	if(x > s1.length())
	{
		if(chs == s2)
			cnt++;
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		bool flag = true;
		for(int j = 0;j < mp[i].first.length();j++)
		{
			if(chs[x+j] != mp[i].first[j])
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			string temp = chs;
			for(int j = 0;j < mp[i].second.length();j++)
			{
				chs[x+j] = mp[i].second[j];
			}
			dfs(x+1);
			chs = temp;
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q;
	cin>>n>>q;
	for(int i = 1;i <= n;i++)
		cin>>mp[i].first>>mp[i].second;
	while(q--)
	{
		cin>>s1>>s2;
		cout<<cnt<<endl;
	}
	return 0;
}
