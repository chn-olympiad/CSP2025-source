#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[10000002];
int main()
{
    string s;
    cin>>s;
    int n=length_error(s);
    for (int i=1;i<=n;i++)
    {
		if(s[i]>='A'&&s[i]<='z')
		{
			n--;
			continue;
		}
		a[i]=s[i];
    }
    sort(a+n,a+n+1);
    for (int i=n;i>=1;i--)
    {
		cout<<a[i];
    }
    return 0;
}
