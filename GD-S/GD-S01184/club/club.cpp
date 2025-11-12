#include<bits/stdc++.h>
using namespace std;
int t,n,a[100000][3],l,b[200][100][100][100];
int xz(int m,int x,int y,int z)
{
    if(m==n)
    {
        return 0;
    }
    if(b[m][x][y][z]!=0)
        return b[m][x][y][z];
    int p=0,o=0,u=0;
    if(x+1<=l)
    {
        p=xz(m+1,x+1,y,z)+a[m][0];
    }
    if(y+1<=l)
    {
        o=xz(m+1,x,y+1,z)+a[m][1];
    }
    if(z+1<=l)
    {
        u=xz(m+1,x,y,z+1)+a[m][2];
    }
    b[m][x][y][z]=max(max(p,o),u);
    return b[m][x][y][z];
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int q=0;q<t;q++)
    {
        cin>>n;
        l=n/2;
        for(int i=0;i<n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        cout<<xz(0,0,0,0)<<endl;
        memset(b,0,sizeof(b));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
