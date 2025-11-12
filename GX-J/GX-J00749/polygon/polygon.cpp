#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n],Y[100000][3];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long kk=0,mm=0;
    for(int i=0;i<n;i++)
    {
        int kkk=kk;
        int d=0;
        for(int j=0;j<i;j++)
        {
            d+=a[j];
        }
        Y[kk][0]=d+a[i];
        Y[kk][1]=a[i];
        Y[kk][2]=i+1;
        for(int j=kk+1;j<=kk*2;j++)
        {
            Y[j][0]=d+a[i]-Y[j-kk-1][0];
            Y[j][1]=Y[kk][1];
            Y[j][2]=Y[kk][2]-Y[j-kk-1][2];
            kkk++;
        }
        kk=kkk+1;
    }

    for(int i=0;i<kk;i++)
    {
        if(Y[i][0]>Y[i][1]*2&&Y[i][2]>=3){mm++;}
    }
    cout<<mm%998244353;

    return 0;
}
