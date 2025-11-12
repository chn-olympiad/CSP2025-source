#include <bits/stdc++.h>
using namespace std;
long long m,n,a[1145141],flag1 = 1,flag10 = 1,cnt = 0,cnt2= 0,cnt3 = 0;
int check(int q,int p)
{
    int num = 0;
    for(int i = q;i <= p;i ++)
    {
        if(a[i] == -21474836) return 0;
        num = num ^ a[i];
    }
    if(num == n) return 1;
    return 0;
}
void xg(int q,int p)
{
    for(int i = q;i <= p;i ++) {
        a[i] = -21474836;
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin >> m >> n;
    for(int i = 1;i <= m;i ++)
    {
        cin >> a[i];
        if(a[i] != 1) {
            flag1 = 0;
        }
        if(a[i] != 1 && a[i] != 0)
        {
            flag10 = 0;
        }
    }
    //ai = 1
    if(flag1 == 1)
    {
        if(n > 1) {
            cout << 0;
            return 0;
        }
        else if(n == 1) {
            cout << m;
            return 0;
        } else if(n == 0) {
            cout << m / 2;
            return 0;
        }
    }
    //ai = 1 or 0
    if(flag10 == 1) {
        if(n == 1) {
            cnt = 0;
            for(int i= 1;i <= m;i ++) {
                cnt += a[i];
            }
            cout << cnt;
        } else if(n == 0) {
            cnt2 = 0;
            for(int i = 1;i <= m;i ++)
            {
                if(a[i] == 0) cnt2 ++;

            }
            for(int i =1;i <= m;i ++) {
                if(a[i] == 1 && a[i + 1] == 1) {
                    cnt2 ++;
                    a[i] = 0;
                    a[i + 1] = 0;
                }
            }
            cout << cnt2;
        } else {
            cout << 0;
            return 0;
        }
    }
    //baoli
    for(int j = 0;j < m;j ++) {
        for(int i = 1;i <= m;i ++) {
			if(i+j>m) break;
            if(check(i,i + j) == 1) {
                cnt3 ++;
                xg(i,i + j);
            }
        }
    }
    cout << cnt3;
    return 0;
}

