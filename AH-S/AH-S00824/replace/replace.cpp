#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200010],s2[200010];
string t1,t2;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    while(q--)
    {
		cin>>t1>>t2;
		string str1,str2;
		str1=str2="";
		for(int i=0;i<t1.size();i++)
		{
			if(t1[i]!=t2[i])
			{
				str1.push_back(t1[i]);
				str2.push_back(t2[i]);
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s1[i].find(str1)!=string::npos&&s2[i].find(str2)!=string::npos)
			{
				if(t1.find(s1[i])!=string::npos&&t2.find(s2[i])!=string::npos)
				{
					if(t1.find(s1[i])==t2.find(s2[i])) cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
    return 0;
}
