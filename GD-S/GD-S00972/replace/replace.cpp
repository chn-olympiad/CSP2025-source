#include<bits/stdc++.h>
using namespace std;
int n,q,cnt=0;
string s1[2001],s2[2001],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[++cnt]>>s2[++cnt];
	}
	while(q--)
	{
		cin>>t1>>t2;
		bool f=false;
		for(int i=1;i<=cnt;i++)
		{
			if(t1.find(s1[i])==1)
			{
				cout<<1<<endl;
				f=true;
			}
		}
		if(f==false) cout<<0<<endl;
	}
	return 0;
} 
