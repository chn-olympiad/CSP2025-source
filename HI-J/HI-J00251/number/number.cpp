#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s="";
	long long x,ans=0,sum=0;
	cin>>s;
	x=s.size();
	for(int i=0;i<x;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]+=s[i]-'0';
			ans++;
		}
	}
	sort(a,a+x);
	for(int i=x-1;i>=0;i--)
	{
		if(sum==ans)
		{
			break;
		}
		cout<<a[i];
		sum++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
