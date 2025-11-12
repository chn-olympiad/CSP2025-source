#include<bits/stdc++.h>
using namespace std;
string s;
long long b=0;
bool f=0;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.size();
	for(long long i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			b++;
			a[b]=int(s[i])-48;
		}
	}
	sort(a+1,a+b+1);
	for(long long i=b;i>=1;i--)
	{
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
