#include <bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=1,len=s.length();
    for(int i=0;i<len;i++)
    {
		if(s[i]>='0'&&s[i]<='9')
		{
		    a[l]=s[i]-'0';
		    l++;
	    }
	}
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<l;i++)
	cout<<a[i];
    return 0;
}
