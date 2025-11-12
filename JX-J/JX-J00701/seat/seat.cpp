#include<bits/stdc++.h>
using namespace std;
int n,m;
int xb2=0;
int b[10010];
int a[10010][10010];
int cddx(int x,int y)
{
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++) cin>>b[i];
    int p=b[0];
    sort(b,b+n*m,cddx);
    for(int j=0;j<m;j++)
    {
        if(j%2==0)
        {
            int xb1=0;
            while(xb1<n)
            {
                a[xb1][j]=b[xb2];
                xb1++;
                xb2++;
            }
        }
        else if(j%2==1)
        {
            int xb1=n-1;
            while(xb1>=0)
            {
                a[xb1][j]=b[xb2];
                xb1--;
                xb2++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==p) cout<<j+1<<' '<<i+1;
        }
    }
    return 0;
}
