#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int s,z;
    cin>>s;
    z=sizeof(s)/sizeof(s[0]);
    int a[z];
    string sum[z];
    for(int i=0;i<sizeof(s)/sizeof(s[0]);i++)
    {
        if(a[i]-"0">=0 && a[i]-"0"<=9)
        {
            sum[i]=a[i]-"0";
        }
    }
    sort(sum,sum+sizeof(s)/sizeof(s[0]));
    for(int i=sizeof(s)/sizeof(s[0])-1;i>=0;i--)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}


