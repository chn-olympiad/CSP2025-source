#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int l;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int x;
    l=s.size();
    int sum=0;
    for (int i=0;i<l;i++)
    {
        if (s[i]<='9'&&s[i]>='0')
        {

            x=s[i];
            a[sum]=x-48;
            sum++;
        }
    }
    sort(a,a+sum);

    if (a[sum-1]==0)
    {

        cout<<0;
        return 0;
    }
    for (int i=sum-1;i>=0;i--)
    {

        cout<<a[i];
    }
    return 0;
}
