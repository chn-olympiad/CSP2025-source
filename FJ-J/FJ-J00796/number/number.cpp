#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			k+=1;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}
