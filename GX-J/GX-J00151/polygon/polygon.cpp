#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;
int a,b,c;
int main()
{
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
		cin>>a>>b>>c;
		if(a+b>c&&a+c>b&&b+c>a)	cout<<1;
		else  cout<<0;
		return 0;
}

