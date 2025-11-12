#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
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
    long long d=0;
    long long f=0;
    long long ans=0;
    for(int i=1;i<=n;)
    {
        ans=a[i];
        if(ans==k)
        {
            f++;
            i++;
            continue;
        }
        bool c=false;
        for(int j=i+1;j<=n;j++)
       {
           ans=ans^a[j];
           if(ans==k)
           {
               d=j;
               c=true;
                f++;
                break;
           }
       }
       if(c)
       {
           i=d+1;
       }
       else{i++;}

    }
    cout<<f;
    return 0;
}
