#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[1000005],cnt=0,sum=0;
	std::cin>>s;
	long long n=s.size();
	for(int i=0;i<n;i++)
	{
	    if(s[i]=='0')a[cnt]=0;
		else if(s[i]=='1')a[cnt]=1;	
		else if(s[i]=='2')a[cnt]=2;	
		else if(s[i]=='3')a[cnt]=3;	
		else if(s[i]=='4')a[cnt]=4;	
		else if(s[i]=='5')a[cnt]=5;	
		else if(s[i]=='6')a[cnt]=6;	
		else if(s[i]=='7')a[cnt]=7;	
		else if(s[i]=='8')a[cnt]=8;	
		else if(s[i]=='9')a[cnt]=9;
		else{
			sum++;
		}
		cnt++;	
	}
	std::sort(a,a+cnt+1,cmp);
	for(int i=0;i<n-sum;i++)
	{
		std::cout<<a[i];
	}
	return 0;
}
