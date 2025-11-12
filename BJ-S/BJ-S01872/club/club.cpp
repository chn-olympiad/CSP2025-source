#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long t, n, num[100005][3], temp[150005];
long long cnta, cntb, cntc;
bool flag[100005][3];
struct student
{
    long long id, val;
}a[100005], b[100005], c[100005];
bool cmp(student x, student y)
{
    if (x.val != y.val) return x.val > y.val;
    return x.id < y.id;
}
bool bmp(long long x, long long y)
{
    return x > y;
}
long long uni(long long p, int type)
{
    long long ch = p + 1;
    if (type == 0)
    {
        while ((flag[a[ch].id][1] || flag[a[ch].id][2]) && ch <= n)
        {
            ch++;
        }
    }
    else if (type == 1)
    {
        while ((flag[b[ch].id][0] || flag[b[ch].id][2]) && ch <= n)
        {
            ch++;
        }
    }
    else
    {
        while ((flag[c[ch].id][0] || flag[c[ch].id][1]) && ch <= n)
        {
            ch++;
        }
    }
    return min(ch, n + 1);
}
void modify(long long x)
{
    long long tempa = num[x][0] - a[uni(cnta, 0)].val, tempb = num[x][1] - b[uni(cntb, 1)].val, tempc = num[x][2] - c[uni(cntc, 2)].val;
    //cout << "templ" << uni(cnta, 0) << ' ' << uni(cntb, 1) << ' ' << uni(cntc, 2) << endl;
    //cout << "tempr" << a[uni(cnta, 0)].val << ' ' << b[uni(cntb, 1)].val << ' ' << c[uni(cntc, 2)].val << endl;
    //cout << "temp" << tempa << ' ' << tempb << ' ' << tempc << endl;
    //cout << "flag" << flag[x][0] << ' ' << flag[x][1] << ' ' << flag[x][2] << endl;
    if (flag[x][0] && flag[x][1] && flag[x][2])
    {
        if (tempa >= tempb && tempa >= tempc)
        {
            flag[x][1] = false;
            if (uni(cntb, 1) <= n)
            {
                flag[b[uni(cntb, 1)].id][1] = true;
                cntb = uni(cntb, 1);
            }
            flag[x][2] = false;
            if (uni(cntc, 2) <= n)
            {
                flag[c[uni(cntc, 2)].id][2] = true;
                cntc = uni(cntc, 2);
            }
        }
        else if (tempb >= tempa && tempb >= tempc)
        {
            flag[x][0] = false;
            if (uni(cnta, 0) <= n)
            {
                flag[a[uni(cnta, 0)].id][0] = true;
                cnta = uni(cnta, 0);
                //cout << "hi" << cnta;
            }
            flag[x][2] = false;
            if (uni(cntc, 2) <= n)
            {
                flag[c[uni(cntc, 2)].id][2] = true;
                cntc = uni(cntc, 2);
            }
        }
        else
        {
            flag[x][1] = false;
            if (uni(cntb, 1) <= n)
            {
                flag[b[uni(cntb, 1)].id][1] = true;
                cntb = uni(cntb, 1);
            }
            flag[x][0] = false;
            if (uni(cnta, 0) <= n)
            {
                flag[a[uni(cnta, 0)].id][0] = true;
                cnta = uni(cnta, 0);
                //cout << "uh";
            }
        }
    }
    else if (flag[x][0] && flag[x][1])
    {
        if (tempa < tempb)
        {
            flag[x][0] = false;
            if (uni(cnta, 0) <= n)
            {
                flag[a[uni(cnta, 0)].id][0] = true;
                cnta = uni(cnta, 0);
                //cout << "?";
            }
        }
        else
        {
            flag[x][1] = false;
            if (uni(cntb, 1) <= n)
            {
                flag[b[uni(cntb, 1)].id][1] = true;
                cntb = uni(cntb, 1);
            }
        }
    }
    else if (flag[x][0] && flag[x][2])
    {
        if (tempa < tempc)
        {
            flag[x][0] = false;
            if (uni(cnta, 0) <= n)
            {
                flag[a[uni(cnta, 0)].id][0] = true;
                cnta = uni(cnta, 0);
                //cout << "hey";
            }
        }
        else
        {
            flag[x][2] = false;
            if (uni(cntc, 2) <= n)
            {
                flag[c[uni(cntc, 2)].id][2] = true;
                cntc = uni(cntc, 2);
            }
        }
    }
    else if (flag[x][2] && flag[x][1])
    {
        if (tempc <= tempb)
        {
            flag[x][2] = false;
            if (uni(cntc, 2) <= n)
            {
                flag[c[uni(cntc, 2)].id][2] = true;
                cntc = uni(cntc, 2);
            }
        }
        else
        {
            flag[x][1] = false;
            if (uni(cntb, 1) <= n)
            {
                flag[b[uni(cntb, 1)].id][1] = true;
                cntb = uni(cntb, 1);
            }
        }
    }
    //cout << "what";
}
int main()
{
    freopen("club1.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        memset(flag, false, sizeof(flag));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        cin >> n;
        long long ans = 0;
        cnta = n / 2, cntb = n / 2, cntc = n / 2;
        for (int i = 1; i <= n; i++)
        {
            a[i].id = b[i].id = c[i].id = i;
            cin >> a[i].val >> b[i].val >> c[i].val;
            num[i][0] = a[i].val, num[i][1] = b[i].val, num[i][2] = c[i].val;
        }
        sort(a + 1, a + n + 1, cmp);
        sort(b + 1, b + n + 1, cmp);
        sort(c + 1, c + n + 1, cmp);
        //for (int i = 1; i <= n; i++) cout << a[i].val << ' ' << b[i].val << ' ' << c[i].val << endl;
        for (int i = 1; i <= n / 2; i++)
        {
            flag[a[i].id][0] = true;
            flag[b[i].id][1] = true;
            flag[c[i].id][2] = true;
        }
        //for (int i = 1; i <= n; i++) cout << flag[i][0] << ' ' << flag[i][1] << ' ' << flag[i][2] << endl;
        for (int i = 1; i <= n; i++)
        {
            modify(i);
            //cout << cnta << endl;
        }
        int sum = 0;
        //cout << cnta << ' ' << cntb << ' ' << cntc << endl;
        for (int i = 1; i <= cnta; i++)
        {
            if (flag[a[i].id][0])
            {
                sum++;
                temp[sum] = a[i].val;
                //cout << a[i].val << ' ';
            }
        }
        //cout << endl;
        for (int i = 1; i <= cntb; i++)
        {
            if (flag[b[i].id][1])
            {
                sum++;
                temp[sum] = b[i].val;
                //cout << b[i].val << ' ';
            }
        }
        //cout << endl;
        for (int i = 1; i <= cntc; i++)
        {
            if (flag[c[i].id][2])
            {
                sum++;
                temp[sum] = c[i].val;
                //cout << c[i].val << ' ';
            }
        }
        //cout << endl;
        sort(temp + 1, temp + n + 1, bmp);
        for (int i = 1; i <= n; i++) ans += temp[i];
        cout << ans << endl;
    }
    return 0;
}