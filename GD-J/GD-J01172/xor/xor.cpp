#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int x(int a,int b)
{
	string s,ss,sa,sb,sc,sd;
	int ans;
	while(a>0) 
	{
		s+=a%2+'0';
		a/=2;
	}
	while(b>0) 
	{
		ss+=b%2+'0';
		b/=2;
	}
	if(s.size()>ss.size()) for(int i=1;i<=s.size()-ss.size();i++) ss+='0';
	else for(int i=1;i<=ss.size()-s.size();i++) s+='0';
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==ss[i]) sa+='0';
		else sa+='1';
	}
	for(int i=sa.size()-1;i>=0;i--) sb+=sa[i];
	bool f=false;
	for(int i=0;i<sb.size();i++)
	{
		if(sb[i]>'0') f=true;
		if(f) sc+=sb[i];
	}
	for(int i=sc.size()-1;i>=0;i--) sd+=sc[i];
	for(int i=0;i<sd.size();i++) ans+=pow(2,i)*(sd[i]-'0');
	return ans;
}
int xa(int a,int b)
{
	if(a==b) return 0;
	else return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0;
	bool f=true;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]>1) f=false; 
	}
	if(f)
	{
		for(int i=1;i<=n;i++)
		{
			int ans=a[i];
			for(int j=i;j<=n;j++)
			{
				if(j!=i) ans=xa(ans,a[j]);
				if(ans==k) cnt++;
			} 
		}
	}
	for(int i=1;i<=n;i++)
	{
		int ans=a[i];
		for(int j=i;j<=n;j++)
		{
			if(j!=i) ans=x(ans,a[j]);
			if(ans==k) cnt++;
		} 
	}
	cout<<cnt;
	return 0;
 } 
