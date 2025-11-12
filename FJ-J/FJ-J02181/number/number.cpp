#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000020],a1,t;
int main()
{
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	t=s.size();
	for(int i=0;i<t;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a1++;
			a[a1]=(s[i]-'0');
		}
	}
	sort(a+1,a+a1+1);
	for(int i=a1;i>=1;i--)cout<<a[i];
	return 0;	
} 
