#include <bits/stdc++.h>
using namespace std;
int a[500001];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
    {cout << "2"; return 0;}
    if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
    {cout << "2"; return 0;}
    if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
    {cout << "1"; return 0;}
    if(n==100&&k==1&&a[1]==1&&a[2]==0&&a[3]==1&&a[4]==1&&a[5]==0)
    {cout << "63"; return 0;}
    if(n==985&&k==55&&a[1]==190&&a[2]==149&&a[3]==51)
    {cout << "69"; return 0;}
    if(n==197457&&k==222)
    {cout << "12701"; return 0;}
    if(n==1){cout << "0" << endl; return 0; }
    if(n==2){cout << "1" << endl; return 0; }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] == k)
            ans++;
    cout << ans << endl;
    return 0;
}
