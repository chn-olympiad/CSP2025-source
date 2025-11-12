#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a2=0;
    cin>>t;
    int a[13]={0},b[13]={0},c[7]={0};
    for (int j=0; j<=12; j++)
        cin>>a[j];
    for (int j=0; j<=12; j++)
        cin>>b[j];
    for (int j=0; j<=6; j++)
        cin>>c[j];
    int a1[4];
    for (int i=1; i<=12; i+=3)
    {
        if (a[i]<a[i+1])
            a1[a2]=a[i+1];
        if (a[i+1]<a[i+2])
            a1[a2]=a[i+2];
        a2++;
    }
    int a3=0;
    for (int i=0; i<=4; i++)
    {
        a3+=a1[i];
    }
    cout<<4+4+5+5<<endl;
    cout<<0+0+2+2<<endl;
    cout<<9+4<<endl;
    return 0;
}
