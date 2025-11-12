#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
ll a[500010];
bool vis[500010];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    bool flag1 = true, flag2 = true;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(a[i] != 1)   flag1 = false;
        if(a[i] > 1)    flag2 = false;
    }
    if(flag1 && k == 0)   cout << n << '\n';
    else if(flag2){
        ll cnt = 0;
        if(k == 0)
            for(int i = 0;i < n;i++){
                if(a[i] == 0)   cnt++;
                if(i != 0 && a[i] == 1 && a[i-1] == 1 && !vis[i] && !vis[i-1])  cnt++, vis[i-1] = 1, vis[i] = 1;
            }
        else
            for(int i = 0;i < n;i++)
                if(a[i] == 1)   cnt++;
        cout << cnt << '\n';
    }
    else{
        ll now = a[0], cnt = 0;
        for(int i = 1;i < n;i++){
            if(now == k)    cnt++, now = a[i];
            else            now ^= a[i];
        }
        if(now == k)    cnt ++;
        cout <<cnt << '\n';
    }
    return 0;
}
