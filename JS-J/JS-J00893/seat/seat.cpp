#include<bits/stdc++.h>
using namespace std;
const int MAXN=10;
const int MAXM=10;
struct point_
{
    bool IR = 0 ;
    int point;
} Point_[MAXN*MAXM+3];
bool cmp(point_ a , point_ b)
{
    return a.point >= b.point;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m; // n:line m:column
    cin >> n >> m;
    for(int i = 0 ; i < n*m ; i++)
    {
        cin >> Point_[i].point;
    }
    Point_[0].IR = 1;
    // for(int i = 0 ; i < n*m ; i++)
    // {
    //     printf("%d , %d\n",Point_[i].point,Point_[i].IR);
    // }
    // printf("\n");
    sort(Point_,Point_+n*m,cmp);
    int cnt = 0;
    for(int i = 1 ; i <= m ; i++) // i:column
    {
        if (i % 2 == 1) for(int j = 1 ; j <= n ; j++) //j:line
        {
            // printf("%d:%d %d\n",cnt,i,j);
            if (Point_[cnt].IR)
            {
                printf("%d %d",i,j);
                return 0;
            }
             cnt++;
        }
        if (i % 2 == 0) for(int j = n ; j >= 1 ; j--)
        {
                    // printf("%d:%d %d\n",cnt,i,j);
            if (Point_[cnt].IR)
            {
                printf("%d %d",i,j);
                return 0;
            }
             cnt++;
        }

    }
}
