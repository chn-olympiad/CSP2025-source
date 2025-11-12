#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool cmp(int x,int y)
{
    return x > y;
}
int d[5][100005],maxn[100005],cha[100005],p[100005],num[5];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,s;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        cin >> n;
        s = 0;
        memset(maxn,0,sizeof(maxn));
        memset(cha,0,sizeof(cha));
        memset(p,0,sizeof(p));
        memset(num,0,sizeof(num));
        for(int j = 1;j <= n;j++)
        {
            cin >> d[1][j] >> d[2][j] >> d[3][j];
            int max = d[1][j];
            int min = d[1][j];
            p[j] = 1;
            if(d[2][j] > max)
            {
                max = d[2][j];
                p[j] = 2;
            }
            if(d[3][j] > max)
            {
                max = d[3][j];
                p[j] = 3;
            }
            if(d[2][j] < min)
            {
                min = d[2][j];
            }
            if(d[3][j] < min)
            {
                min = d[3][j];
            }
            int mid = d[1][j]+d[2][j]+d[3][j]-min-max;
            cha[j] = max-mid;
            maxn[j] = max;
            //cout << cha[j] << " " << maxn[j] << endl;
        }
        for(int j = 1;j <= n;j++)
        {
            s += maxn[j];
            num[p[j]]++;
        }
        //cout << s << endl;
        for(int j = 1;j <= 3;j++)
        {
            if(num[j] > (n/2))
            {
                for(int k = 1;k <= n;k++)
                {
                    if(p[k] != j) cha[k] = 30000;
                }
                sort(cha,cha + n + 1);
                for(int k = 1;k <= num[j] - (n/2);k++)
                {
                    s -= cha[k];
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}