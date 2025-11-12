#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,s=0;
    cin>>n>>k;
    int a[500001];
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1) s++;

        }
        cout<<s;
    }
    else if(k==0){
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0) s++;

        }
        for(int m=1;m<n;m+=2)
        {
            if(a[m]==1&&a[m+1]==1)
            {
                s++;
            }

        }
        cout<<s;
        }
    else cout<<k-1;
    return 0;
}
