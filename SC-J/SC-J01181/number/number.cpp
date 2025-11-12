#include<bits/stdc++.h>
using namespace std;
string s;
int x;
int a[1000010];
int k=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		x=s[i]-'0';
		if(x>=0 && x<=9)
		{
			a[k]=x;
			k++;
		}
	}
	sort(a+1,a+k);
	for(int i=k-1;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
} 