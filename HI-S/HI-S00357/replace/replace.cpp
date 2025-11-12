#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
const int N=2e5+10;
string s[N][2];
bool check(string s1,string s2,int k)
{
	int len=s1.size();
	int rlen=s[k][0].size();
	for(int i=0;i<=len-rlen;i++)
	{
		if(s1.substr(i,rlen)==s[k][0])
		{
			string now=s1.substr(0,i);
			now+=s[k][1];
			now+=s1.substr(i+rlen,len-i-rlen);
//			cout<<now;
			if(now==s2)
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	string qs1,qs2;
	while(q--)
	{
		cin>>qs1>>qs2;
		cnt=0;
		for(int i=0;i<n;i++)
		{
			if(check(qs1,qs2,i))
			cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
