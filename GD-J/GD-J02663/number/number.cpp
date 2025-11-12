#include<bits/stdc++.h>
using namespace std;
int b[1000005],bl=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<=a.size()-1;i++)
	{
		if(a[i]-'0'>=0 and a[i]-'0'<=9)
		{
			bl++;
			b[bl]=a[i]-'0';
		}
	}
	sort(b+1,b+1+bl);
	for(int i=bl;i>=1;i--)
	{
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
