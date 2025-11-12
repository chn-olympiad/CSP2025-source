#include<bits/stdc++.h>
using namespace std;
int s[1000005],nu,n;
string a;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a;
    for(int i=0;i<=a.size()-1;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            s[nu]=a[i]-'0';
            nu++;
        }
    }
    sort(s,s+nu--);
    while(nu>=0)
    {
        cout<<s[nu];
        nu--;
    }
	return 0;
}
