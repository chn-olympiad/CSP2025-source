#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int c,r,d=0,mc=1,b,a=0,e=0;
    cin>>c>>r;
    cin>>b;
    for(int i=2;i<=c*r;i++)
    {
        cin>>d;
        if(d>b)
            mc++;
    }
    for(int i=1;i<=c;i++)
    {
        a++;
        if(a%2==1)
            for(int j=1;j<=r;j++)
            {
                e++;
                if(e==mc)
                {
                    cout<<i<<" "<<j;
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
            }
        else
            for(int j=r;j>=1;j--)
            {
                e++;
                if(e==mc)
                {
                    cout<<i<<" "<<j;
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
            }
    }
}
