#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e2 + 5;
int n,m,xr,cnth = 0,cntl = 1;
int a[N] = {0};
bool flag = 1,b = 0;

bool cmp (int x,int y)
{
    return x > y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++){
        cin >> a[i];
    }
    xr = a[1];
    sort(a + 1,a + n * m + 1,cmp);
    for (int i = 1;i <= n * m;i++){

        if (cnth == 1 && cntl % 2 == 0){
            flag = b = 1;
            cntl++;
        }
        else if (cnth == n && cntl % 2 == 1){
            flag = 0;
            b = 1;
            cntl++;
        }
        if (flag && !b) cnth++;
        else if (!flag && !b) cnth--;
        b = 0;
        if (a[i] == xr){
            cout << cntl << ' ' << cnth;
            break;
        }
    }
    return 0;
}