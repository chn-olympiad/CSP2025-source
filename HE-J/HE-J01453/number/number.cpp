#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length(),num=0;
	if(n==1) cout<<s;
	else
	{
		for(int i=0;i<n;i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				a[num]=s[i]-'0';
				num++;
			}
		}
		sort(a,a+num);
		for(int i=num-1;i>=0;i--)
		{
			cout<<a[i];
		}
	}
	return 0;
}
