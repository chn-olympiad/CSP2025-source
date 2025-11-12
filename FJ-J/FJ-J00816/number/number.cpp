#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a,g;
	long long b[1005],d=0;
	cin>>s;
	long long n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>=48 && s[i]<=57)
		{
			d++;
			if(s[i]==49) b[d]=1;
			else if(s[i]==50) b[d]=2;
			else if(s[i]==51) b[d]=3;
			else if(s[i]==52) b[d]=4;
			else if(s[i]==53) b[d]=5;
			else if(s[i]==54) b[d]=6;
			else if(s[i]==55) b[d]=7;
			else if(s[i]==56) b[d]=8;
			else if(s[i]==57) b[d]=9;
			else if(s[i]==48) b[d]=0;
		}
	}
	sort(b+1,b+d+1);
	for(int i=d;i>=1;i--)
	{
		cout<<b[i];
	}
	return 0;
}
