#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],s;
bool t=true;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
            t=false;
    }

    if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
                s++;
        }
        cout<<s;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
                s++;
            if(a[i]==1&&a[i-1]==1)
            {
                s++;
                a[i]=0;
                a[i-1]=0;
            }
        }
        cout<<s;
    }
    return 0;
}
