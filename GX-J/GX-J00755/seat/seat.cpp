#include<bits/stdc++.h>
using namespace std;
int n,m,a[200];
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    int k = n * m;
    for(int i=0;i<k;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+k,cmp);
    int v = 1;
    while(v<k&&a[0]<a[v])
    {
        v++;
    }
    int t = v / (2 * n) * 2 + 1, w = v % (2 * n);
    if(w==0){
        cout << t-1 << ' ' << 1;
        return 0;
    }
    if(w>n)
    {
        t += 1;
        w -= n;
        w = n - w + 1;
    }
    cout << t << ' ' << w;
    return 0;
}
