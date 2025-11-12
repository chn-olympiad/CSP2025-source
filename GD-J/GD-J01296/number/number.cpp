#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a[250005];
	long long sum=0;
	for(int i=0;i<=s.size();i++)
	{
		if(int(s[i])<=57 && int(s[i])>=48)
		{
			sum++;
			a[sum]=int(s[i])-48;
		}
	}
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
