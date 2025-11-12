#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[10000001],n=10000001;
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++)
    {

        if(s[i]>='0' && s[i]<='9')
        {
            a[i]=s[i];
        }

    }
    sort(a+1,a+1+n);
    for(int i=1; i<=n; i++)
    {
        cout << a[i];
    }
    return 0;
}
