#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string a;
int s[10];
int main()
{
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
		cin>>a;
		int len=a.size();
		for(int i=0;i<=len-1;i++)
			if(a[i]-'0'<=9) s[a[i]-'0']++;
		for(int i=9;i>=0;i--)
			for(int j=1;j<=s[i];j++)
				cout<<i;
		return 0;
}

