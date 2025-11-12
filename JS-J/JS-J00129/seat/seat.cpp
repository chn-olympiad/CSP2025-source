#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
int mp[N][N];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n * m;i++)
    {
        scanf("%d",&a[i]);
    }
    int tmp = a[1];
    sort(a + 1,a + n * m + 1,greater<int>());
    int nowx = 1,nowy = 1;
    int flag = 1;
    for(int i = 1;i <= n * m;i++)
    {
        mp[nowx][nowy] = a[i];
        if(a[i] == tmp)
        {
            printf("%d %d",nowy,nowx);
            return 0;
        }
        if(flag == 1)
        {
            if(nowx == n)
            {
                nowy++;
                flag = 2;
            }
            else
            {
                nowx++;
            }
        }
        else if(flag == 2)
        {
            if(nowx == 1)
            {
                nowy++;
                flag = 1;
            }
            else
            {
                nowx--;
            }
        }
    }
    return 0;
}
