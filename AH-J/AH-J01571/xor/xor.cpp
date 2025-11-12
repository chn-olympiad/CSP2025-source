#include<bits/stdc++.h>
using namespace std;
int a[500005],v,t;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i==1)
        {
            t=a[i];
            v++;
        }
        else{
            if(a[i]==t)
                v++;
        }
    }
    if(v==n)
       {
           cout<<"0"<<endl;
            return 0;
       }

    return 0;
}
