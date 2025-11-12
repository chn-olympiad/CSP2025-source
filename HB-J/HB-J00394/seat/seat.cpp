#include<bits/stdc++.h>
using namespace std;
struct node
{
    int num,p;
}stu[105];
bool cmp(node n,node m)
{
    return n.num > m.num;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)
    {
        cin >> stu[i].num;
        stu[i].p = i;
    }
    sort(stu+1,stu+n*m+1,cmp);
    int x = 1,y = 1;
    for(int i = 1;i <= m;i++)
    {
         for(int j = 1;j <= n;j++)
         {
             if(stu[n*(i-1)+j].p == 1)
             {
                 cout << x << " " << y;
                 return 0;
             }
             else if(j == n)x++;
             else
             {
                 if(i % 2 == 0)y--;
                 else y++;
             }
         }
    }
    return 0;
}
