#include<bits/stdc++.h>
using namespace std;
int a[1000010],c,k;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    k=s.size();
    for(int i=0;i<k;i++)
    {
		if('0'<=s[i] and s[i]<='9')
		{
			c++;
			a[c]=s[i]-'0';
		}
	}
	sort(a+1,a+c+1);
	for(int i=c;i>=1;i--)
	{
		cout<<a[i];
	}
    return 0;
}
