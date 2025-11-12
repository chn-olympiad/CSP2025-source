#include <bits/stdc++.h>
using namespace std;
int t,n[6],a[6][100005][4],f[50004][50004][50004],a1,b,c,maxx;
void f1(int k)
{
    for (int j=1;j<=n[k];j++)
    {
        f[a1][b][c]=max(max(f[a1][b][c],f[a1-1][b][c]+a[k][j][1]),max(f[a1][b-1][c]+a[k][j][2],f[a1][b][c-1]+a[k][j][3]));
    }
}
int main()
{
    freopen('club.in','r',stdin);
    freopen('club.out','w',stdout);
    cin >> t;
    for (int i=1;i<=t;i++)
    {
        cin >> n[i];
        for (int j=1;j<=n[i];j++)
        {
            for (int k=1;k<=3;k++)
            {
                cin >> a[i][j][k];
            }
        }
    }
    for (int i=1;i<=t;i++)
    {
        a1=1,b=1,c=1,maxx=0;
        for (int j=1;j<=n[i];j++)
        {
            f[0][0][1]=max(f[0][0][1],a[i][j][3]);
            f[0][1][0]=max(f[0][1][0],a[i][j][2]);
            f[1][0][0]=max(f[1][0][0],a[i][j][1]);
        }
        for (int j=1;j<=n[i];j++)
        {
            f[0][1][1]=max(f[0][0][1]+a[i][j][2],f[0][1][0]+a[i][j][3]);
            f[1][0][1]=max(f[0][0][1]+a[i][j][1],f[1][0][0]+a[i][j][3]);
            f[1][1][0]=max(f[0][1][0]+a[i][j][1],f[1][0][0]+a[i][j][2]);
        }
        f1(i);
        while (a1<=n[i]/2)
        {
            a1++;
            f1(i);
            a1--;
            b++;
            f1(i);
            b--;
            c++;
            f1(i);
            c--;
            b++;
            c++;
            f1(i);
            a1++;
            b--;
            f1(i);
            b++;
            c--;
            f1(i);
            c++;
            f1(i);
        }
        for (int x=0;x<=n[i]/2;x++)
        {
            for (int y=0;y<=n[i]/2;y++)
            {
                maxx=max(maxx,f[x][y][n[i]-x-y]);
            }
        }
        cout << maxx << endl;
    }
    return 0;
}
