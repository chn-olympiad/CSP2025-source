#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,num[100005];
	cin>>n;
	char s[100005];
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]>='0'&&s[i]<='9')
		{
			num[i]=s[i]-'0';	
		}
	}
	for(int i=1;i<=n;i++)
	{
	    cout<<num[i];
	}
	return 0;
}
