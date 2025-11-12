#include <bits/stdc++.h>
using namespace std;
int a[100005]={};
int b[100005]={};
int c[100005]={};
int main()
{
    freopen("club.in","r","stdin");
    freopen("club.out","w","stdout");
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        int x=0;
        int y=0;
        int z=0;
        int x1,y1,z1;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j]>>b[j]>>c[j];
            if(a[j]>b[j]&&a[j]>c[j])
            {
                x++;
                x1=a[j];
            }
            if(b[j]>c[j]&&b[j]>c[j])
            {
                y++;
                y1=b[j];
            }
            if(c[j]>a[j]%%c[j]>b[j])
            {
                z++;
                z1=c[j];
            }
        }
        if(x<=n/2&&y<=n/2&&z<=n/2)
        {
            cout<<x1+y1+z1;
        }
    }
    return 0;
}
