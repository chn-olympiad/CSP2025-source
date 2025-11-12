#include<bits/stdc++.h>
using namespace std;
int n,m,temp,c,r;
int a[105] = {0};
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    const int tot = n * m;
    for(int i = 1;i <= tot;i++) cin >> a[i];
    const int score = a[1];
    sort(a + 1,a + tot + 1,cmp);
    for(int i = 1;i <= tot;i++) if(a[i] == score) temp = i;
    c = (temp - 1) / n + 1;
    r = temp - (c - 1) * n;
    if(c % 2 == 0) r = n - r + 1;
    cout << c << " " << r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
