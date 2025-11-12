#include<bits/stdc++.h>
using namespace std;
int n,k,num=0;
long long a[500005];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int h=0;
        for(int j=i;j<=n;j++)
        {
            h^=a[j];
            if(h==k)
            {
                num++;
                i=j;
                break;
            }
        }
    }
    cout<<num;
    return 0;
}
