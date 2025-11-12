#include <bits/stdc++.h>
using namespace std;
long long A[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long num=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			A[num]=s[i]-'0';
			num++;
		}
	}
	sort(A,A+num);
	long long ans=0;
	for(int i=num;i>=0;i--)
	{
		ans=ans*10+A[i];
	}
	cout<<ans;
	return 0;
 } 
