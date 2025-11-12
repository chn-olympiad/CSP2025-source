#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string a[s.length()];
	int l=0;
    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='0')&&(s[i]<='9'))
        {
            a[l]=s[i];
            l++;
        }
    }
    sort(a,a+l);
    for(int i=l;i>=0;i--)
    {
        cout<<a[i];
    }
	return 0;
}
