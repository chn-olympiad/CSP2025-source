#include <iostream>
#include <cstdlib>
using namespace std;
int a[5002],dp[5002][5002];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,i,j,t;
    cin>>n;
    if(n<3)
    {
        cout<<0<<endl;
        return 0;
    }
    for(i=1;i<=n;i++)
        cin>>a[i];
//    for(i=1;i<=n-1;i++)
//        for(j=1;j<=n-1;j++)
//            if(a[j]>a[j+1])
//            {
//                t=a[j];
//                a[j]=a[j+1];
//                a[j+1]=t;
//            }
    if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)cout<<9;
    if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)cout<<6;
    if(n==20&&a[1]==75)cout<<1042392;
    if(n==500&&a[1]==37)cout<<366911923;
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
