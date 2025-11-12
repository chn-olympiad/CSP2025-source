#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
string s1[200000+10],s2[200000+10],t1,t2;
int n,q,ans;
int tcs[26][200000+10];
bool judge(string a,string b,int ind)
{
	if(a.size()<s1[ind].size())
		return false;
	for(int i=1;i<=tcs[s1[ind][0]-'a'][0];i++)
	{
		if(tcs[s1[ind][0]-'a'][i]+(int)s1[ind].size()-1>=(int)a.size())
			return false;
		int j=tcs[s1[ind][0]-'a'][i],k=0;
		for(;j<=tcs[s1[ind][0]-'a'][i]+(int)s1[ind].size()-1;j++,k++)
			if(a[j]!=s1[ind][k]||b[j]!=s2[ind][k])
				goto next;
		for(;j<(int)a.size();j++)
			if(a[j]!=b[j])
				goto next;
		for(int j=0;j<tcs[s1[ind][0]-'a'][i];j++)
			if(a[j]!=b[j])
				goto next;
		return true;
		next:;
	}
	return false;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--)
	{
		ans=0;
		memset(tcs,0,sizeof(tcs));
		cin>>t1>>t2;
		for(int i=0;i<(int)t1.size();i++)
			tcs[t1[i]-'a'][++tcs[t1[i]-'a'][0]]=i;
		for(int i=1;i<=n;i++)
			if(judge(t1,t2,i))
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}

