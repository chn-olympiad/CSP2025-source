#include <bits/stdc++.h>
using namespace std;
struct node
{
    int weizhi,pos,gongxian;
};node b[100005];
int t,n,cnt,num,zhuan,zpos;
long long ans;
int num2,num3,limit1;
int a[100005][5][8];
bool vis[100005][8],flag2,flag3;
bool cmp(node x,node y)
{
    return x.gongxian>y.gongxian;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(num<t)
    {
        num++;
        ans=0;
        cnt=0;
        cin >> n;
        limit1=n/2;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=3;j++)
            {
                cin >> a[i][j][num];
            }
            ans+=a[i][1][num];
            int g2=a[i][2][num]-a[i][1][num];
            int g3=a[i][3][num]-a[i][1][num];
            cnt++;
            b[cnt].weizhi=2;
            b[cnt].pos=i;
            b[cnt].gongxian=g2;
            cnt++;
            b[cnt].weizhi=3;
            b[cnt].pos=i;
            b[cnt].gongxian=g3;
        }
        sort(b+1,b+(2*n)+1,cmp);
        zhuan=0;
        num2=0;
        num3=0;
        flag2=0;
        flag3=0;
        zpos=1;
        while(zhuan<limit1 || b[zpos].gongxian>=0)
        {

            if (vis[b[zpos].pos][num])
            {
                zpos++;
                continue;
            }
            if (b[zpos].weizhi==2)
            {
                if (flag2)
                {
                    zpos++;
                    continue;
                }
                ans+=b[zpos].gongxian;
                vis[b[zpos].pos][num]=1;
                num2++;
                zhuan++;
            }
            if (b[zpos].weizhi==3)
            {
                if (flag3)
                {
                    zpos++;
                    continue;
                }
                ans+=b[zpos].gongxian;
                vis[b[zpos].pos][num]=1;
                num3++;
                zhuan++;
            }
            if (num2>=limit1)flag2=1;
            if (num3>=limit1)flag3=1;
            if (flag2 && flag3)break;
        }
        cout << ans << endl;
    }
    return 0;
}
