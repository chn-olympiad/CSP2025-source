#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m=-1;int y=0,con=0;
    cin>>n;
    int a[n+2];
    for(int i=0;i<n;i++) cin>>a[i];
    if(n<=3)
    {
        m=max(m,a[0]);
        m=max(m,a[1]);
        m=max(m,a[2]);
        y=a[0]+a[1]+a[2];
        if(y>m) cout<<1;
    }
    else if(n<=10)
    {
        int k=3;
        for(int i=0;i<n*2;i++)
        {
            for(int l=0;l<k;l++)
            {
                m=max(m,a[j]);
                y+=a[j];
            }
            if(y>m) con++;
            if(i%k==0) k++;
        }
        cout<<((con%998)%244)%353;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
