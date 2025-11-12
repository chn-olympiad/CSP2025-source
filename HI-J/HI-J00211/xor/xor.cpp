#include<bits/stdc++.h>
using namespace std;
const int L=5e5+10;
long long n,k,a[L],ans=0,sum=0,s1=0;

long long yihuo(long long x,long long y)
{
	string s1="",s2="",s3="",s4="";
	long long ans=0;
	while(x>0)
	{
		s1.push_back(x%2);
		x/=2;
	}
	while(y>0)
	{
		s2.push_back(y%2);
		y/=2;
	}//转二进制 
	
	int l;
	if(s1.size()<s2.size())
	{
		l=s2.size()-s1.size();
		while(l--)
			s1.push_back('0');
	}
	else if(s1.size()>s2.size())
	{
		l=s1.size()-s2.size();
		while(l--)
			s2.push_back('0'); 
	}//补零
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	
	l=s1.size();
	for(int i=0;i<l;i++)
	{
		if(s1[i]!=s2[i])
			s3.push_back('1');
		else
			s3.push_back('0');
	}//异或 
	
	l=s3.size();
	bool flag=false;
	for(int i=0;i<l;i++)
	{
		if(s3[i]!='0')
			flag=true;
		if(flag)
			s4.push_back(s3[i]);
	}
	if(flag==false)
		s4="0";
	reverse(s4.begin(),s4.end());//得出最终答案的二进制 
	
	l=s4.size();
	for(int i=0;i<l;i++)
		ans+=pow(2,i)*(s4[i]-'0');//得出最终答案
		
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	for(int i=0;i<n;i++)
	{
		int p=i;
		while(p<n)
		{
			sum=a[p],s1=0;
			for(int j=p+1;j<n-i;j++)
			{
				sum=yihuo(sum,a[j]);
				if(sum==k)
				{
					p=j+1;
					s1++;
					ans++;
					break;
				}
			}
			if(s1==0)
			p++;
		}
	}
	cout<<ans;
	return 0;
} 
