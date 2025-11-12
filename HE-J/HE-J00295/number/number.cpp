#include<bits/stdc++.h>
using namespace std;
string a;
char b[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	long long n=a.size();
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		if(int(a[i])-58<=9)
		{
			b[ans]=a[i];
			ans++;
		}
	}
	sort(b,b+ans);
	for(int i=ans-1;i>=0;i--)
	{
		cout<<b[i];
	}
	return 0;
}
