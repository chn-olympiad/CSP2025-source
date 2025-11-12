#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n=0;
    string s;
    cin>>s;
    int a[1000005];
    int l=s.size();
    for(int i=0;i<l;i++)
    {
        if((int)s[i]>47&&(int)s[i]<58)
        {
            a[n]=s[i];
            n+=1;
        }
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--)
    {
        cout<<(char)a[i];
    }
    return 0;
}
