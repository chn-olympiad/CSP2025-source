#include<bits/stdc++.h>
using namespace std;
string s;
int a[100000005];
int num,sum0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num++;
			a[num]=s[i]-'0';
			if(a[num]==0)
			{
				sum0++;
			}
		}
	}
	if(sum0==num)
	{
		cout<<0;
		exit(0);
	}
	sort(a+1,a+num+1,greater<int>());
	for(int i=1;i<=num;i++)
	{
		cout<<a[i];
	}
	return 0;
}
