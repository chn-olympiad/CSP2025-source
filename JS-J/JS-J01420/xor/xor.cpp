#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int ret=0;
    int ret2=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
           ret=1;
        }
        if(a[i]>1)
        {
            ret2=0;
        }
    }
    if(ret==0)
    {
        cout<<n/2;
        return 0;
    }
    if(ret2==1)
    {
        int ret=0;
        if(k==1)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1)
                {
                    ret++;
                }
            }
        }
        else if(k==0)
        {

             for(int i=1;i<=n;i++)
             {
                 if(a[i]==0)
                 {
                     ret++;
                 }
                 if(a[i]==1 && a[i+1]==1)
                 {
                     ret++;i++;
                 }
             }
        }
        cout<<ret;
    }
    return 0;
}
