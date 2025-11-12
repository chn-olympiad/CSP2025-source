#include <bits/stdc++.h>
using namespace std;

const int N=100001;

int t,n;
int b[3]={0};
int c[N]={1};
int m=0;
int ans[N]={0};

void f(int n, int a[][3], int c[], int m, int g, int ans[], int t, int b[])
{
    for(int j=1; j<=3; j++)
    {
        if(b[j-1]==n/2)
        {
            continue;
        }
        c[g]=j;
        b[j-1]++;
        m=m+a[g][j-1];
        if(g==n)
        {
            if(ans[t]<m)
                ans[t]=m;
        }
        else
            f(n, a, c, m, g+1, ans, t, b);
        b[j-1]--;
        m-=a[g][j-1];
    }
    return;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin>>t;

    for(int x=0; x<t; x++)
    {
        cin>>n;
        int a[n][3];
        for(int i=0; i<n; i++)
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        f(n, a, c, m, 0, ans, t, b);
    }

    for(int i=0; i<t; i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
