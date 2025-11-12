//杜庹钊
//GZ-S00251
//安顺市第一高级中学

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

#define int long long

using namespace std;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	string s1[n+5][5];
	string s2[q+5][5];
	int len[n+5]={0};
	int min1=9999999999;
	for(int i=1;i<=n;++i)
	{
		cin>>s1[i][1];
		cin>>s1[i][2];
		len[i]+=s1[i][1].length(); 
		int p=s1[i][1].length();
		min1=min(p,min1);
	}
	
	for(int i=1;i<=q;++i)
	{
		cin>>s2[i][1];
		cin>>s2[i][2];
	}
	
	int MAX=0;
	
	for(int i=1;i<=q;++i)
	{
		int num=0;
		for(int j=1;j<=n;++j)
		{
			if(len[j]==s2[i][1].length())
			num=1;
		}
		if(num)
		{
			continue;
		}
	}
	
	cout<<MAX<<"\n";
	
	return 0;
 } 
