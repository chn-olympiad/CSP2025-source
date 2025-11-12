#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;
int a[10],n;
char c;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c)
	{
			if(c=='0')	a[0]++;
			if(c=='1')	a[1]++;
			if(c=='2')	a[2]++;
			if(c=='3')	a[3]++;
			if(c=='4')	a[4]++;
			if(c=='5')	a[5]++;
			if(c=='6')	a[6]++;
			if(c=='7')	a[7]++;
			if(c=='8')	a[8]++;
			if(c=='9')	a[9]++;
			if(c>='0'&&c<='9')	n++;
	}
	if(a[0]==n){cout<<0;return 0;}
	for(int i=9;i>=0;i--)
		if(a[i]!=0)
			for(int j=1;j<=a[i];j++)
				cout<<i;
	return 0;
}
