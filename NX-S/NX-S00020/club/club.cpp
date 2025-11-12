#include<bits/stdc++.h>
using namespace std;
bool camp(int x,int y)
{
    return x<y;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    int a[100000],b[100000],c[100000];
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        long long z=0;
        cin>>n;
        int c9=0,cb=0,cc=0;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j]>>b[j]>>c[j];
            if(b[i]==0&&c[i]==0)
            {
                c9++;
            }
            if(c[i]==0)
            {
                cb++;
            }
            if(a[j]==b[j]||b[j]==c[j]||a[j]==c[j])
            {
                cc=1;
            }
        }
        int a1=0,a2=0;
        if(c9>1000)
        {
            for(int j=1;j<=n/2;j++)
            {
                sort(a+1,a+n+1);
                sort(b+1,b+n+1);
                z=z+a[n-j+1];

            }
        }
        if(cb>100)
        {
            for(int j=1;j<=n/2;j++)
            {
                sort(a+1,a+n+1);
                sort(b+1,b+n+1);
                z=z+a[n-j+1]+b[n-j+1];

            }
            if(a[n/2]>b[n/2])
            {
                z=z+a[n/2];
            }
        //    else
        //    {
         //       z=z+b[n/2];
           // }
        }
        if(cc==0)
        {
            for(int j=1;i<=n;j++)
            {
                z=z+max(a[j],max(b[j],c[j]));
            }
        }
        cout<<z<<endl;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
