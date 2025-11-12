#include<bits/stdc++.h>
using namespace std;
int a[100002],k=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[k++]=s[i]-'0';
		}
	}
	sort(a+1,a+k);
	for(int i=k-1;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
