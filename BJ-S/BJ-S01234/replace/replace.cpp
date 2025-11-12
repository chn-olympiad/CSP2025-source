#include<bits/stdc++.h>
#define ll long long
#define __ 200005
using namespace std;
string s[__][2];
int n,q,diff[__],st[__],en[__];
int main()
{
	int i,j;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		int pos1,pos2;
		for(j=0;j<s[i][0].length();j++)
			if(s[i][0][j]=='b')
				pos1=j;
			if(s[i][1][j]=='b')
				pos2=j;
		diff[i]=pos1-pos2-1;
		st[i]=pos1;
		en[i]=s[i][0].length()-2-pos2;
	}
	while(q--)
	{
		string s1,s2;
		int pos1,pos2,cnt=0;
		cin>>s1>>s2;
		for(i=0;i<s1.length();i++)
			if(s1[i]=='b')
				pos1=i;
			if(s2[i]=='b')
				pos2=i;
		int df=pos1-pos2,st_=pos1,en_=s1.length()-1-pos2;
		for(i=1;i<=n;i++)
		{
//			cout<<df<<diff[i]<<st_<<st[i]<<en_<<en[i]<<endl;
			if((df==diff[i])&&(st_>=st[i])&&(en_>=en[i]))
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}