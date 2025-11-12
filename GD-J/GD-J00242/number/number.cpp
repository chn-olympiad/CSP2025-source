#include<bits/stdc++.h>
using namespace std;
int const N=1e6+5;
int a[N],h,b;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	h=s.size();
	for(int i=0;i<h;i++)
	{
		b=s[i];
		if(b>=48&&b<=57)
		a[b]++;
		else
		continue;
	}
	for(int i=57;i>=48;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout<<i-48;
		}
	}
	return 0;
} 
