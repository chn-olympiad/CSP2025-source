#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int sti[n];
    int big=0;

    for(int i=0;i<n;i++)
    {

        cin>>sti[i];
        if(sti[i]>big)
        {
            big=sti[i];
        }
    }
    if(n==3)
    {
        if(sti[0]+sti[1]+sti[2]>2*big)
            cout<<1;
    }
    else if(big==1)
    {
        int ans=0;
        for(int i=3;i<=n;i++)
        {
            int a=1;
            for(int j=0;j<i;j++)
            {
                a*=(n-j);
            }
            int b=1;
            for(int j=1;j<=i;j++)
            {
                b*=j;
            }
            a/=b;
            ans+=a;
        }
        cout<<ans;
    }
    else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
