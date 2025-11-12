#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>s1[i]>>s2[i];
	while(q--)
	{
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;++i)
		{
			int pos=-(int)s1[i].length();
			while(~pos)
			{
				pos=t1.substr(pos+s1[i].length()).find(s1[i]);
				if(~pos)
				{
					for(int j=pos;j<pos+(int)s2[i].length();++j)
						t1[j]=s2[i][j-pos];
					if(t1==t2)
						++ans;
					for(int j=pos;j<pos+(int)s1[i].length();++j)
						t1[j]=s1[i][j-pos];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
