#include<bits/stdc++.h>
using namespace std;

struct A
{
    int bianhao;
    int val;
};
A a[210];

bool cmp(A x, A y)
{
    return x.val > y.val;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n *m;i++)
    {
        a[i].bianhao = i;
        cin >> a[i].val;
    }

    sort(a + 1, a + n * m + 1, cmp);
    int tmp = 0;
    for(int i = 1;i <= n * m;i++)
    {
        if(a[i].bianhao == 1)
        {
            tmp = i;
            break;
        }
    }

     if(tmp == 1)
     {
         cout << "1 1" << endl;
         exit(0);
     }
     //cout << "tmp:" << tmp <<endl;
     int tot = tmp;
     int cnt_mbei = 1;
     int cntnow = 0;
     while(tot--)
     {
         if(cntnow == m)
         {
             cnt_mbei++;
             cntnow = 0;
         }
         cntnow++;
     }

    // cout << "cnt_mbei:" << cnt_mbei << " cntnow:" << cntnow << endl;

     cout << cnt_mbei << " ";
     if(cnt_mbei % 2 == 0)//shang_sheng
     {
         cout << m - cntnow + 1 << endl;
     }
     else if(cnt_mbei % 2 == 1)//xia_jiang
     {
         cout << cntnow << endl;
     }
     /*
     if(cntnow == 0)
     {
         if(cnt_mbei % 2 == 0)//shang_sheng
         {
             cout << cnt_mbei << " " << 1 << endl;
         }
         else if(cnt_mbei % 2 == 1)//xia_jiang
         {
             cout << cnt_mbei << " " << m << endl;
         }
     }
     else if(cntnow > 0 && cnt_mbei > 0)
     {
         if(cnt_mbei % 2 == 0)//shang_sheng
         {
             cout << cnt_mbei << " " << m - cntnow << endl;
         }
         else if(cnt_mbei % 2 == 1)//xia_jiang
         {
             cout << cnt_mbei << " " << 1 + cntnow << endl;
         }
     }

    // int tot2 = tmp % m;

    // cout << tot << " ";
    /*
     if(tot == 0)
     {
         cout << "1" << endl;
         /*
         if(tmp == m)
         {
             cout << m << " ";
         }
         else if(tmp < m)
         {
             cout << "1" << endl;
         }

     }

     else if(tot > 0)
     {
         cout << tot + 1 << " ";
     }


     if(tot % 2 == 0)//xiang_shang_pai_lie
     {
         if(tot2 == 0)
         {
             cout << "1" << endl;
         }
         else
         {
             cout << m - tot2 << endl;
         }
     }
     else if(tot % 2 == 1)//xiang_xia_pai_lie
     {
         if(tot2 == 0)
         {
             cout << m << endl;
         }
         else
         {
             cout << 1 + tot2 << endl;
         }
     }
     */
    //cout << tmp << endl;
    return 0;
}
