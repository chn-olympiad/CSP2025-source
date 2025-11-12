#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n=0;
    string s;
    cin>>s;
    int x=s.size();
    int a[x+10];
    for(int i=0;i<x;i++)
    {
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>-1;i--)
	{
		cout<<a[i];
	}
    return 0;
}
