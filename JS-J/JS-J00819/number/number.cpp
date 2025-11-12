#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005],k=1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<='9'&&a[i]>='0')
        {
            b[k]=a[i]-48;
            k++;
        }
    }
    sort(b+1,b+k);
    for(int i=k-1;i>=1;i--)
    {
        cout<<b[i];
    }
    return 0;
}
