#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e5 + 5;
int n,k,ans = 0;
int a[N] = {0};
int sum[N] = {0};
bool vis[N] = {0};

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    sum[0] = 0;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        sum[i] = sum[i - 1] xor a[i];
        if (a[i] == k){
            ans++;
            vis[i] = 1;
        }
    }
    for (int i = 1;i <= n;i++){
        for (int j = i;j <= n;j++){
            if (vis[j]) break;
            if ((sum[j] xor sum[i - 1]) == k){
                i = j;
                ans++;
                break;
            }
            vis[j] = 1;
        }
    }
    cout << ans;
    return 0;
}
