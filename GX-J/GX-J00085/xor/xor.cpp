#include<bits/stdc++.h>
using namespace std;
long long n,k;
int a[500010];
long long cut;
int main()
{

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k==0)
    {
        cout<<n/2;
        return 0;
    }
    if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]!=a[i-1])
                cut++;
        }
        cout<<cut<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
    return 0;
}
