#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001],k;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    k=1;
    int len=s.length();
    for (int i=0;i<len;i++)
    {
    	if ('0'<=s[i] && s[i]<='9')
    	{
    		a[k]=s[i]-'0';
    		k++;
		}
	}
	sort(a+1,a+k,cmp);
	for (int i=1;i<k;i++)
	{
		cout<<a[i];
	}
	return 0;
}

