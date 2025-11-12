#include<bits/stdc++.h>
using namespace std;
int a[100001][3],n,maxx,lim,T,f[101][101];
void consulate(int i,int d1,int d2,int d3,int v)//i当前第几个人，d1社团1已有人数,v当前满意度
{
    maxx=max(maxx,v);
    if(i>n) return;
    int k1=1,k2=1,k3=1;
    if(d1==lim) k1=0; if(d2==lim) k2=0; if(d3==lim) k3=0;
    if(k1) consulate(i+1,d1+1,d2,d3,v+a[i][0]); if(k2) consulate(i+1,d1,d2+1,d3,v+a[i][1]); if(k3) consulate(i+1,d1,d2,d3+1,v+a[i][2]);
}
int smax(int f1,int f2,int f3)
{
    int k1=max(f1,f2);
    return max(k1,f3);
}
void b1()
{
    lim=n/2;
    consulate(1,0,0,0,0);
    cout<<maxx<<endl;
}
void b2()
{
    f[1][0]=a[1][0]; f[0][1]=a[1][1];
        for(int i=2;i<=n-1;i++)
        {
            int i1=min(i,n/2),i2=min(i,n/2);
            for(int d1=i1;d1>=0;d1--)
            {
                for(int d2=i2;d2>=0;d2--)
                {
                    if(d1>=1&&d2>=1) f[d1][d2]=smax(f[d1][d2],f[d1-1][d2]+a[i][0],f[d1][d2-1]+a[i][1]);
                      else if(d1==0&&d2!=0) f[0][d2]=max(f[0][d2],f[0][d2-1]+a[i][1]);
                        else if(d2==0&&d1!=0) f[d1][0]=max(f[d1][0],f[d1-1][0]+a[i][0]);
                }
            }
        }
        cout<<smax(f[n/2][n/2],f[n/2-1][n/2]+a[n][0],f[n/2][n/2-1]+a[n][1])<<endl;
        if(T!=1)
        {
            for(int i=0;i<=n/2;i++)
                for(int j=0;j<=n/2;j++)
                    f[i][j]=0;
        }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        maxx=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        if(n<=30) b1();
          else b2();
    }
    return 0;
}
