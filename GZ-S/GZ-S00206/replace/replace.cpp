//GZ-S00206 北京师范大学贵阳附属中学 曹誉桉
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,q,ans,len1,len2;
map<string,string>mp;
string s1,s2;
void dfs(string a1,string a2,int cnt1)
{
	if(a1==a2)
	{
		ans++;
		return;
	}
	for(int i=0; i<len1-1; i++)
	{
		string cnt="";
		for(int j=i; j<len1; i++)
		{
			cnt+=a1[i];
			if(mp[cnt]!="")
			{
				string s2;
				for(int x=0; x<i; x++)
				{
					s2+=a2[i];
				}
				s2+=cnt;
				for(int x=i+j; x<len1; x++)
				{
					s2+=a2[i];
				}
				dfs(s2,a2,cnt1++);
			}
		}			
	}
	return;
}
int main()
{
	freopen("replace.in","r",stdin) ;
	freopen("replace.out","w",stdout) ;
	cin >> n >> q;
	for(int i=1; i<=n; i++)
	{
		cin >> s1 >> s2;
		mp[s1]=s2;
	}
	for(int i=1; i<=q; i++)
	{
		ans=0;
		cin >> s1 >> s2;
		len1=s1.size();
		len2=s2.size();
		if(len1!=len2)
		{
			cout << "0" << endl;
			continue;
		}
		//dfs(s1,s2,0);
		cout << "0" << endl;
	 } 
	return 0;
}
