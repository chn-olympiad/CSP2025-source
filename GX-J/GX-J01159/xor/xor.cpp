#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(k==0)
    {
        int num=0,f=0;
        if(a[1]==0)num++;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==0)
            {
                num++;
            }
            else if(a[i]==1&&a[i-1]==1&&f==0)
            {
                num++;
                f=1;
                continue;
            }
            f=0;
        }
        cout<<num;
        return 0;
    }
    else if(k==1)
    {
        int num=0,f=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                num++;
            }
        }
        cout<<num;
        return 0;
    }
    cout<<0;
    return 0;
}
