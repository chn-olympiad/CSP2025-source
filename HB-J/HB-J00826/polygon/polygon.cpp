#include <bits/stdc++.h>
using namespace std;
int n;
int a[1145141],flag1 = 1,cnt = 0,book[1145141],ans[1145414];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >>n;
    for(int i= 1;i <= n;i ++)
    {
        cin >> a[i];
        if(a[i] != 1) {
            flag1 = 0;
        }
    }
    if(n == 3) {
        int maxn = -1145,num = 0;
        for(int i= 1;i <= n;i ++)
        {
            num += a[i];
            maxn = max(maxn,a[i]);
        }
        if(num > maxn * 2) {
            cout << 1;
            return 0;
        } else {
            cout << 0;
            return 0;
        }
    }
    if(flag1)
    {
        int r = 0;
        int sum = 0;
        for(int i = 3;i <= n;i ++) {
            cnt = 0;
            int j = n - i + 1,jj = n - i;
            if(jj == 0) sum += 1;
            while(jj != 0) {
                //if(cnt == i - 1) break;
                if(j == 0) {
                    jj --;
                    j = i - 1;
                    cnt ++;
                    if(jj == 0)
                    {
                        sum ++;
                        break;
                        }

                }
                //if(cnt == i- 1) break;
                sum += j;
                j -= 1;
               // cout << 1;
            }
            //cout << sum << ' ';

        }
        cout << sum;
        return 0;
    }
    return 0;
}
