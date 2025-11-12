#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
map<string,string> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int res=0;
		for(int i=0;i<t1.size();i++)
			for(int j=1;j+i-1<t1.size();j++)
			{
				if(mp.count(t1.substr(i,j)))
				{
					string nt=t1.substr(0,i)+mp[t1.substr(i,j)]+t1.substr(i+j,t1.size()-j-i);
					if(nt==t2)res++;
				}
			}
		printf("%d\n",res);
	}
	return 0;
}
