#include <bits/stdc++.h>
using namespace std;
int b[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int j=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            j++;
            b[j]=a[i]-'0';
        }
    }
    sort(b+1,b+j+1);
    for(int i=j;i>=1;i--)
    {
        cout<<b[i];
    }
    return 0;
}
