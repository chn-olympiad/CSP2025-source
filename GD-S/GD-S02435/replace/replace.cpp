#include<bits/stdc++.h>//Ren5Jie4Di4Ling5%
#define ll long long
#define endl "\n"
using namespace std;
int n;
ll ans;
map<string,string>m;
map<string,bool>have;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int q;cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s,ss;cin>>s>>ss;
		m[s]=ss;have[s]=1;
	}
	for(int o=1;o<=q;o++)
	{
		ans=0;
		string s,ss;cin>>s>>ss;
		int len=s.size();
		for(int i=0;i<len;i++)
		{
			string sss="";
			for(int j=0;j+i<len;j++)
			{
				sss+=s[i+j];int l=sss.size();
				if(have[sss])
				{
					string ssss="";
					for(int k=0;k<i;k++)ssss+=s[k];
					for(int k=0;k<l;k++)ssss+=m[sss][k];
					for(int k=i+l;k<len;k++)ssss+=s[k];
//					cout<<j<<' '<<l<<' '<<j+l<<' '<<len<<' '<<ssss<<endl;
					if(ssss==ss)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/ 
