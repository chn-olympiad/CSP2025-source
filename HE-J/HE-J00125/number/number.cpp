#include<bits/stdc++.h>
long long a[1000030];
using namespace std;
bool ma(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	long long m=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'==0||s[i]-'0'==1||s[i]-'0'==2||s[i]-'0'==3||s[i]-'0'==4||s[i]-'0'==5||s[i]-'0'==6||s[i]-'0'==7||s[i]-'0'==8||s[i]-'0'==9)
		{
			m++;
			a[m]=s[i]-'0';
		}
	}
    sort(a+1,a+m+1,ma);
    for(int i=1;i<=m;i++)
    {
    	cout<<a[i];
	}
	return 0;
}
