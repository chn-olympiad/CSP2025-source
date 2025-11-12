#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=s.size();
	int a[n+5];
	long long j=1; 
	for (long long i=0;i<s.size();i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			a[j]=s[i]-'0';
			j++;
		}
	}
	j--;
	sort(a+1,a+j+1);
	for (int i=j;i>=1;i--)
		cout<<a[i];
	return 0;
}
