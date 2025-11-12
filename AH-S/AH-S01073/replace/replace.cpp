//replace.cpp
#include<bits/stdc++.h>
using namespace std;
string s1="",s2="";
string ss[200010][2],qu[200010][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>ss[i][1]>>ss[i][2];
	for(int i=1;i<=q;i++) cin>>qu[i][1]>>qu[i][2];
	for(int i=1;i<=q;i++)
	{
		bool pd=0;
		for(int j=0;j<qu[i][1].size();j++)
		{
			if(qu[i][1][j]!=qu[i][2][j]&&!pd) pd=j,s1+=qu[i][1][j],s2+=qu[i][2][j];
			if(qu[i][1][j]!=qu[i][2][j]&&pd) pd=j;
		}
	}
	return 0;
}
