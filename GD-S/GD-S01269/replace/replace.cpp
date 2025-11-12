/*
16:46 开题感觉要起飞了 
16：49 毅然决定暴力 
17:45  T++
17:45  M++
17:45  D++打了1H都没打出来W++，C++ ； 
算了不争了，就这样吧。

应该算是几乎最后一次参加CSPS了

中考以后不知道会不会继续学 

还有半个小时，OI生涯就算结束了

感觉这次比以往都难，上不了200了，大概100~150吧 

这道题太难受了， string的函数不会用，不知道问题在哪里

样例勉强过了吧，希望数据水一点喵 

回望这4年，一言难尽。

其实想写多点上个迷惑行为打赏的，但是写不下去了QwQ 
 
*/ 
#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#include<vector>
using namespace std;
map<string,string> ma;
int solve(string s1,string s2)
{
	int len1=s1.size(),len2=s2.size();
	if(len1!=len2)return 0;
	int l=0x3f3f3f3f,r=-0x3f3f3f3f;
	for(int i=0;i<len1;i++)
	{
		if(s1[i]!=s2[i])
		{
			l=min(l,i);
			r=max(r,i);
		}
	}
	int ans=0;
	for(int i=0;i<=l;i++)
	{
		for(int j=r;j<=len1;j++)
		{
			string check1="";
			string check2="";
			for(int k=i;k<=j;k++)check1+=s1[k];
			for(int k=i;k<=j;k++)check2+=s2[k];
			cout<<check1<<" "<<check2<<"\n";
			if(ma[check1]==check2)
			{
				ans++;
			}
		}
	}
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		ma[s1]=s2;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		cout<<solve(s1,s2)<<"\n";
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
