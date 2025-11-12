#include<bits/stdc++.h>
using namespace std;

int n,q;
string s1[200010],s2[200010];
string t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(s1[i].size()>t1.size())
				continue;
			for(int j=0;j<t1.size()-s1[i].size()+1;j++)
			{
//				cout<<s1[i].size()<<"\n";
				if(s1[i][0]==t1[j])
				{
					int k=j,l=0;
					while(s1[i][l]==t1[k]&&l<s1[i].size())
						l++,k++;
					if(l==s1[i].size())
					{
						string awa=t1.substr(0,j)+s2[i]+t1.substr(k,s1[i].size());
//						cout<<j<<"　"<<l<<" "<<k<<"\n";
//						cout<<awa<<"\n";
						if(awa==t2)
							ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
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