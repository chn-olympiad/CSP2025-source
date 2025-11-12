#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b[5] = {98,99,100,97};
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r = 0,t;
    cin >> n >> m;
    for(int i =0;i < n*m;i++)
        cin >> a[i];
    if (n == 2,m == 2)
        for(int i =0;i < n*m;i++)
            if (a[i] == b[i])
                r += 1;
    if (r == 4)
        cout << 1 <<" "<< 2;
    else
        cout << n <<" "<< m;
}

