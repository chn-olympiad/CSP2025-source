#include<bits/stdc++.h>
using namespace std;
int a[1000001]={};
int sum=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			sum++;
			a[sum]=s[i]-'0';
		}
	}
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}