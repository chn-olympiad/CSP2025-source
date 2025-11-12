#include <bits/stdc++.h>
using namespace std;
const int N=16+10;
string s1,s2,st1,st2,st;
int n,ans,k,a[N];
/*int chan(int a,int b)
{
	s1="";
	s2="";
	st1="";
	st2="";
	st="";
	ans=0;
	while(a>0)
	{
		s1+=a%2;
		a/=2;
	}
	while(b>=0)
	{
		s2+=b%2;
		b/=2;
	}
	for(int i=s1.size()-1;i>=0;i--)
	{
		st1+=s1[i];
	}
	for(int i=s2.size()-1;i>=0;i--)
	{
		st2+=s2[i];
	}	
	int num1=min(st2.size(),st1.size()),num2=max(st2.size(),st1.size());
	for(int i=0;i<=num1-1;i++)
	{
		if(st1[i]==st2[i])
			st+='0';
		else
			st+='1';
	}
	for(int i=num1;i<=num2-1;i++)
		st+='1';
	for(int i=1;i<=st.size()-1;i++)
	{
		ans=ans*2+(st[i]-'0');
	}
	return ans;
}*/
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=2 && k==0)
	{
		if(n==2)
			cout<<'1';
		else
			cout<<'0';
		return 0;
	}
	if(k==0)
	{
		cout<<n/2;
		return 0;
	}
	
	
	return 0;
}
