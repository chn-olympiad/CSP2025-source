#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
    long long a[10];
	getline(cin,s);
	long long len=s.size();
	for(long long i=0;i<=len-1;i++)
	  if(s[i]>='0'&&s[i]<='9'){
	     s[i]+=0;
	     a[s[i]+0]++;
	  }
	for(int i=9;i>=0;i--)
	{
		for(long long j=1;j<=a[i];j++)
		  cout<<a[i];
	}
	return 0;
}
