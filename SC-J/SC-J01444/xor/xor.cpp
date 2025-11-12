#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,k,a[N],maxn;
string fun(int n)
{
	string s3;
	while(n!=0)
	{
		s3=char(n%2+'0')+s3;
		n=n/2;
	}
	return s3;
}
int fun1(string s)
{
	int sum=1,t=1;
	for(int i=s.size()-2;i>=0;i--)
	{
		sum=sum+s[i]*t;
		t=t*2;
	}
	return sum;
}
int yihuo(int a,int b)
{
	string s=fun(a),s1=fun(b),s2;
	if(s.size()<s1.size())
	{
		swap(s,s1);
	}
	for(int i=1;i<=s.size()-s1.size();i++)
	{
		s1='0'+s1;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s1[i])
		{
			s2=s2+'1';
		 } 
		 else
		 {
		 	s2=s2+'0';
		 }
	}
	return fun1(s2);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(maxn<a[j]-a[i]&&yihuo(a[i],a[j])==k)
			{
				maxn=j-i+1;
			}
		}
	}
	cout<<maxn;
	return 0;
}