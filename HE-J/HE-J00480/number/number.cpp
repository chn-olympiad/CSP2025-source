#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+7;
int qw(char s)
{
	int n;
	if(s=='0')
		n=0;
	if(s=='1')
		n=1;
	if(s=='2')
		n=2;
	if(s=='3')
		n=3;
	if(s=='4')
		n=4;
	if(s=='5')
		n=5;
	if(s=='6')
		n=6;
	if(s=='7')
		n=7;
	if(s=='8')
		n=8;
	if(s=='9')
		n=9;
	return n;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
	string s;
	std::cin>>s;
	int l=s.size(),m=0;
	int a[l]={};
	for(int i=0;i<l;i++)
	{
		if(/*s[i]=='0'||*/s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			a[i]=qw(s[i]);
			m++;
		}
		else
		{
			continue;
		}
	}
//	if(m==l)
//	{
//		sort(a+1,a+m+1);
//		for(int i=l;i>0;i--)
//		{
//			cout<<a[i];
//		}
//		return 0;
//	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[j]<=a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
		cout<<a[i];
	}
	return 0;
}
