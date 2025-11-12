#include<bits/stdc++.h>
using namespace std;
int er(int i)
{
	int ans=0;
	int k=1;
	while(i!=0)
	{
		ans+=(k*(i%2));
		k*=10;
		i/=2;
	}
	return ans;
}
string si,sj;
string yihuo(int i,int j) // same -> 1 different -> 0
{
	si=to_string(i);
	sj=to_string(j);
	if(si.size()>sj.size())
	{
		string sjj=sj;
		sj="";
		for(int i=0;i<si.size();i++)
		{
			sj+='0';
		}
		reverse(sjj.begin(),sjj.end());
		for(int i=0;i<sjj.size();i++)
		{
			sj[i]=sjj[i];
		}
		reverse(sj.begin(),sj.end());
	}
	if(sj.size()>si.size())
	{
		string sii=si;
		si="";
		for(int i=0;i<sj.size();i++)
		{
			si+='0';
		}
		reverse(sii.begin(),sii.end());
		for(int i=0;i<sii.size();i++)
		{
			si[i]=sii[i];
		}
		reverse(si.begin(),si.end());
	}
	string ans="";
	reverse(sj.begin(),sj.end());
	reverse(si.begin(),si.end());
	for(int i=si.size()-1;i>=0;i--)
	{
		if(si[i]==sj[i]) ans+='0';
		else ans+='1';
	}
	return ans;
}
int sttonum(string s)
{
	int ans=0;
	int k=1;
	for(int i=s.size()-1;i>=0;i--)
	{
		ans+=(s[i]-'0')*k;
		k*=10;
	}
	return ans;
}
long long a[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=er(a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int s1,s2;
		for(int j=1;j<=i;j++)
		{
			if(j==1)
			{
				s1=(a[j]);
				s2=(a[j+1]);
			}
			else
			{
				int ans=sttonum(yihuo(s1,s2));
				s1=ans;
				s2=a[j+1];
			}
			
		}
		if(er(k)==s1) ans++;
	}
	cout<<ans;
	return 0;
}
