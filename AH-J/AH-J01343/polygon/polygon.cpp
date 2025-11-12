#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans,sum,maxx;
int main(void)
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {

        cin>>a[i];
        sum+=a[i];
    }
    if(sum<=2)
    {
        cout<<0;
    }
    else
    {
        if(n<3)cout<<0;
        else
        {
            if(n==3)
            {

                for(int i=0;i<n;i++)
                {
                    maxx=max(a[i],maxx);
                }
                if(sum>maxx*2)ans=1;
                cout<<ans;
            }
            else
            {


            }

        }
    }
}
