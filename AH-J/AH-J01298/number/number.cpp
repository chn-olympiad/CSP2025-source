#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[11]={0};
	int x;
	int n=s.size();
	for(int i=0;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			x=s[i]-'0';
			a[x]++;
		}
	}
	
	for(int i=9;i>=0;i--)
	{
		while(a[i]>0)
		{
			cout<<i;
			a[i]--;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
