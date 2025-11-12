#include<bits/stdc++.h>
using namespace std;
#define int long long

struct A
{
    int bianhao, val;
};

A a[100010], b[100010], c[100010];
int cnta = 0, cntb = 0, cntc = 0;

bool cmp(A x, A y)
{
    return x.val > y.val;
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        bool flag = true;
        for(int i = 1;i <= n;i++)
        {
            cnta++;
            cntb++;
            cntc++;
            a[cnta].bianhao = i;
            b[cntb].bianhao = i;
            c[cntc].bianhao = i;
            cin >> a[cnta].val >> b[cntb].val >> c[cntc].val;
            if(b[cntb].val == 0 && c[cntc].val == 0)
            {

            }
            else
            {
                flag = false;
            }
        }
        if(n >= 2 && n <= 30)//bao_li
        {


            sort(a + 1, a + n + 1, cmp);
            sort(b + 1, b + n + 1, cmp);
            sort(c + 1, c + n + 1, cmp);

            int ret = 0;
            int tmp = n / 2;
            int tnta = cnta;
            int tntb = cntb;
            int tntc = cntc;
            int cnt2a = 0;
            int cnt2b = 0;
            int cnt2c = 0;

            for(int i = 1;i <= cnta;i++)
            {
                cnt2a++;
                ret += a[i].val;
                tnta--;
                if(cnt2a >= tmp)
                {
                    break;
                }
            }
            for(int i = 1;i <= cntb;i++)
            {
                cnt2b++;
                ret += b[i].val;
                tntb--;
                if(cnt2b >= tmp)
                {
                    break;
                }
            }
            for(int i = 1;i <= cntc;i++)
            {
                cnt2c++;
                ret += c[i].val;
                tntc--;
                if(cnt2c >= tmp)
                {
                    break;
                }
            }

            //cnt2a_mei_yong_le
            //cnt2b_mei_yong_le
            //cnt2c_mei_yong_le

            if(tnta != 0)
            {
                for(int i = n - tnta;i <= n;i++)
                {
                    int maxx = max(b[i].val, c[i].val);
                    if(maxx == b[i].val)
                    {
                        if(cnt2b < tmp)
                        {
                            ret += b[i].val;
                            cnt2b++;
                        }
                        else
                        {
                            ret += c[i].val;
                        }
                    }
                }
            }
            if(tntb != 0)
            {
                for(int i = n - tntb;i <= n;i++)
                {
                    int maxx = max(a[i].val, c[i].val);
                    if(maxx == a[i].val)
                    {
                        if(cnt2a < tmp)
                        {
                            ret += a[i].val;
                            cnt2a++;
                        }
                        else
                        {
                            ret += c[i].val;
                        }
                    }
                }
            }
            if(tntc != 0)
            {
                for(int i = n - tntc;i <= n;i++)
                {
                    int maxx = max(a[i].val, b[i].val);
                    if(maxx == a[i].val)
                    {
                        if(cnt2a < tmp)
                        {
                            ret += a[i].val;
                            cnt2a++;
                        }
                        else
                        {
                            ret += b[i].val;
                        }
                    }
                }
            }
            cout << ret << endl;
        }
        else if(flag == true)
        {
            int tmp = n / 2;
            int ret = 0;
            for(int i = 1;i <= tmp;i++)
            {
                ret += a[i].val;
            }
            cout << ret << endl;
            exit(0);
        }
    }
    return 0;
}
