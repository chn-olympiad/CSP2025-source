#include<bits/stdc++.h>
using namespace std;
long long n,k,sum_a=0,ans;
struct node {
    int a,id;
}a[500010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].a;
        if(a[i].a==k)
        {
            sum_a++;
        }
    }
    if(sum_a>=n-1)
    {
        cout<<sum_a;return  0;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i].a==k)
        {
            ans++;
        }
        else {
            long long  q=a[i].a;
            for(int j=i+1;j<=n;j++)
            {
                if((q^a[j].a)==k)
                {
                    i=j;ans++;
                    //cout<<(q^a[j].a)<<" ";
                }
                else{
                    q=(q^a[j].a);
                }

            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}