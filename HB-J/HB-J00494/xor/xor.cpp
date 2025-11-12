#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[500010];
int n,k;
int main()
{

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    //sync_with_stdio(0);
    scanf("%d %d",&n,&k);
    //cerr<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        ll t;
        scanf("%lld",&t);
        x[i]=x[i-1]^t;
    }
    int l=1,cnt=0;
    int idx=0;
    int r=n;
    for(;l<=n;l++)
    {
        r=n;
        bool flag=0;
        for(int i=0;i<=r-l;i++)
        {
            for(int j=l;j+i<=r;j++)
            {

                if(((x[j+i])^(x[j-1]))==k)
                {
                    idx++;
                    //cerr<<cnt<<'{'<<idx<<':'<<'/';
                    //for(int q=j;q<=j+i;q++)cerr<<x[q]-x[q-1]<<'['<<q<<"] "<<' ';
                    //cerr<<'/'<<endl;
                    flag=1;
                    r=i+j;
                    break;
                }
            }
        }
        //cerr<<cnt<<'|';
        if(flag)
            cnt+=1;
        l=r;

    }
    cout<<cnt;
    //cerr<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
