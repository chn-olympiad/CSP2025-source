#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000010];
int j=0;
int main() 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		int n=a[i]-'0';
		if(n>=0 && n<=9)
		{
			b[j]=n;
			j++;
		}
	}
	sort(b-1,b+j);
	for(int i=j-1;i>=0;i--)
	{
		cout<<b[i];
	}
	return 0;
}
