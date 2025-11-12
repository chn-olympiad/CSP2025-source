//活得那么久，记得却那么少，也许我该心存感激 
//我忘记了所有悲剧，看到的皆是奇迹
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
map<string,string>m;
string t1,t2;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;cin>>s1>>s2;
		m[s1]=s2;
	}
	while(q--)
	{
		cin>>t1>>t2;
		int l1=t1.size(),l2=t2.size();
		if(l1!=l2){puts("0");continue;}
		int st=-1,ed=0;
		for(int i=0;i<l1;i++)
		{
			if(st==-1&&t1[i]!=t2[i])st=i;
			if(t1[i]!=t2[i])ed=i;
		}
//		printf("%d %d\n",st,ed);
		string dif="",aim="";
		for(int i=st;i<=ed;i++)dif=dif+t1[i],aim=aim+t2[i];
		int ans=0;
		for(int len=ed-st+1;len<=l1;len++)
		{
			string s1=dif,s2=aim;
			for(int i=min(st,l1-len+1);i>=0;i--)
			{
				int j=i+len-1;
//				cout<<s1<<' '<<s2<<'\n';
				if(m[s1]==s2)ans++;
				s1=t1[i-1]+s1;s2=t2[i-1]+s2;
			}
			dif=dif+t1[st+len];aim=aim+t2[st+len];
		}
		cout<<ans<<'\n';
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
