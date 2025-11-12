#include<bits/stdc++.h>
using namespace std;
int a[500002];
int n,k,ans;
bool b[500002];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i]=x^a[i-1];
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        int x=a[i-1]^a[i];
        if(x==k)
        {
            ans++;
            b[i]=true;
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x=a[j+i-1]^a[j-1];
            if(x!=k) continue;
            bool ok=true;
            for(int k=j;k<=j+i-1;k++)
            {
                if(b[k])
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                ans++;
                for(int k=j;k<=i+j-1;k++)
                {
                    b[k]=true;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
