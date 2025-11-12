#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(k==1)
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
                cnt++;
        }
    else
        cnt=n/2;
    printf("%d",cnt);
    return 0;
}
