#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=0;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			j++;
			num[j]=s[i]-'0';
		}
	}
	sort(num+1,num+1+j);
	for(int i=j;i>=1;i--)
	{
		cout<<num[i];
	}
	return 0;
}
