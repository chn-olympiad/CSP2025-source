/*
	1.
	
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[1100000],k,j=0;
bool pd;
int main()

{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[++k]=s[i]-'0';
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--)
	{
		if(a[i]==0&&pd==0)
			j++;
		else
			break;
	}
	if(k-j==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=k-j;i>=1;i--)
		cout<<a[i];
	return 0;
} 
