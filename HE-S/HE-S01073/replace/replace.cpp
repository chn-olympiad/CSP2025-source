#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

vector< pair<string,string> >v;
int ans;
void DFS(string s1,string s2)
{
	for(int i=0;i<v.size();i++)
	{
		for(int l=0;l<s1.size();l++)
		{
			for(int r=l;r<=s1.size();r++)
			{
				if((s1.substr(l,r)==v[i].first))
				{
					string ss=s1;
					ss.replace(l,r,v[i].second);
					if(ss==s2)
						ans++;
				}
			}
		}
	}
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		v.push_back(make_pair(s1,s2));
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		ans=0;
		cin>>s1>>s2;
		DFS(s1,s2);
		cout<<ans<<endl;
	}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
