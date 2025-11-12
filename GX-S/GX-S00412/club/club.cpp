#include<bits/stdc++.h>
using namespace std;
bool b[100010][10];
struct node
{
    int d, a1, w;
};
bool cmp(node x,node y)
{
    return x.d > y.d;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m = 0, m1 = 0, m2 = 0, m3 = 0;
        node a[300010];
        cin >> n;
        int l = -1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                l++;
                cin >> a[l].d;
                b[i][j] = 0;
                a[l].w = i;
                a[l].a1 = j;
            }
        }
        n /= 2;
        sort(a, a+l+1, cmp);
        int i = 0;
        while(i <= l)
        {
            if(!b[a[i].w][a[i].a1])
            {
                if(a[i].a1 == 1&&m1<n)
                {
                    b[a[i].w][2] = 1;
                    b[a[i].w][3] = 1;
                    m1++;
                    m += a[i].d;
                }
                else if(a[i].a1 == 2&&m2<n)
                {
                    b[a[i].w][1] = 1;
                    b[a[i].w][3] = 1;
                    m2++;
                    m += a[i].d;
                }
                else if(a[i].a1 == 3&&m3<n)
                {
                    b[a[i].w][1] = 1;
                    b[a[i].w][2] = 1;
                    m3++;
                    m += a[i].d;
                }
            }
            i++;
        }
        cout << m <<endl;
    }
    return 0;
}
