#include<bits/stdc++.h>
using namespace std;
char a[1005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int n=strlen(a);
    for(int i=0;i<=n;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            cout<<a[i];
        }
    }


    return 0;
}
