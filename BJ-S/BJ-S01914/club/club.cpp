#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],d[5];
int sum;
struct node{
    int m,b;
    int minn = INT_MAX,bb;
    int mm,bc;
}c[100005];
bool cmp(node x,node y)
{
    return x.m > y.m;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum = 0;
        for(int i = 1;i <= n;i++)
        {
            c[i].m = 0;
            c[i].mm = 0;
            c[i].minn = 20005;
            c[i].b = 0;
            c[i].bb = 0;
            c[i].bc = 0;
        }
        d[1] = n / 2,d[2] = n / 2,d[3] = n / 2;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= 3;j++)
            {
                cin >> a[i][j];
                if(a[i][j] > c[i].m)
                {
                    c[i].m = a[i][j];
                    c[i].b = j;
                }
                if(a[i][j] < c[i].minn)
                {
                    c[i].minn = a[i][j];
                    c[i].bb = j;
                }
            }
            c[i].bc = 6 - c[i].b - c[i].bb;
            c[i].mm = a[i][c[i].bc];
        }
        sort(c + 1,c + n + 1,cmp);
        for(int i = 1;i <= n;i++)
        {
            if(d[c[i].b])
            {
                sum+= c[i].m;
                d[c[i].b]--;
            }
            else if(d[c[i].bc])
            {
                sum += c[i].mm;
                d[c[i].bc]--;
            }
            else
            {
                sum += c[i].minn;
                d[c[i].bb]--;
            }
        }
        cout << sum<<endl;
    }
    return 0;
}