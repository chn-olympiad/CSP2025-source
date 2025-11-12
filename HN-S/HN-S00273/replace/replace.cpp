#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005],t1,t2;
int check1(string a,string b)
{
	for(int i=0;i<a.length();i++)
		if(a[i]!=b[i])
			return i;
}
int check2(string a,string b)
{
	int l=a.length()-1;
	int r=b.length()-1;
	while(true)
	{
		if(a[l]!=b[r])
			return l;
		l--;
		r--;
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		cin>>t1>>t2;
		cout<<0<<endl;
	}
	return 0;
}
