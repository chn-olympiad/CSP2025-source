#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,sta;
string s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		string l,r;
		int ans=0;
		vector<int> pos;
		cin>>l>>r;
		int lenl=l.length(),lenr=r.length();
		for(int i=0;i<min(lenr,lenl);i++)
		{
			if(l[i]!=r[i])
			{
				pos.push_back(i);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(s2[i]==r&&s1[i]==l)
			{
				ans++;
			}
		}
//		cout<<pos[0]<<'\n';
		for(int i=1;i<=n;i++)
		{
			int ll=s1[i].length();
			if(ll==lenr) continue;
			for(int j=0;j<pos.size();j++)
			{
				sta=pos[j];
				string s;
				for(int k=sta;k<sta+ll;k++)
				{
					s=s+r[k];
				}
				if(pos[pos.size()-1]<=sta+ll-1&&s==s2[i]&&pos[0]>=sta)
				{
					ans++;
				}
//				cout<<s<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
 */