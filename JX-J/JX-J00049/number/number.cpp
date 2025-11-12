#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int m[a.size()];
    int k=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&& a[i]<='9')
            m[k++]=a[i]-'0';
    }
    sort(m,m+k);
    for(int i=k-1;i>=0;i--)
        cout<<m[i];
    return 0;
}
