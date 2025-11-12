#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int t,n;
int nm;
int ch;
int a[100][100],c1[100];
int k,m11,m12=1,m21,m22=1,m31,m32=1;
int club(int a[100][100]);
int m1(int a[100][100]);
int m2(int a[100][100]);
int m3(int a[100][100]);
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int h;
    int a1[100];
    cin>>t;
    cin>>n;
    cin>>ch;
    for(int i=0;i<t;i++)
    {

        cin>>c1[i];
    }

    for(int s=0;s<t;s++)
    {

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>a[i][j];
            }
        }
        {
            for(int j=0;j<3;j++)
            {
                nm=n;
            }
        }
    }
    cout<<t+n/3;
    return 0;
}
