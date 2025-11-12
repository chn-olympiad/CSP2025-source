#include<bits/stdc++.h>
using namespace std;
int b[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int x;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		x=a[i]-'0';
		if(x>=0&&x<=9) b[x]++;
	}
	for(int i=9;i>=0;i--)
	{
		if(b[i])
		{
			while(b[i]--)
			{
				cout<<i;
			}
		}
	}
 } 
