#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    int a[100010],h=0;
    h=0;
    for(int i=0;i<n;i++)
    {
        if(isdigit(s[i]))
        {

            a[h]=s[i]-'0';
            h+=1;
        }
    }
    if(h==1)
    {
        cout<<a[0];
        return 0;
    }
    sort(a,a+h);
    for(int i=h-1;i>=0;i--) cout<<a[i];
    return 0;
}
