#include<bits/stdc++.h>

using namespace std;

int m, n, sum, s = 1;
int a[1000] = {0};

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> m >> n;// hang lie
    sum = m * n;
    for(int i = 0; i < sum; i ++)
    {
        cin >> a[i];
        if(a[i] > a[0]) s ++;
    }
    int c, r;
    c = ceil((double)s / (double)n);
    r = s % m;
    if(r == 0) r = m;
    if(c % 2 == 0) r = m - r + 1;
    cout << c << " " << r << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}

