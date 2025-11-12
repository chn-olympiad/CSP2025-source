#include<bits/stdc++.h>
using namespace std;
int a[11000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=1;
	string c;
	cin>>c;
	int l=c.size();
	for(int i=0;i<l;i++)
	{
		if('0'<=c[i]&&c[i]<='9')
		{
			a[j++]=c[i]-'0';
		}
	}
	sort(a+1,a+j);
	for(int i=j-1;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
} 
