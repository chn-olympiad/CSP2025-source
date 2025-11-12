#include<bits/stdc++.h>
using namespace std;
#define PLL pair<int,int>
inline int read(){
    int f = 1,x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-')
            f = -1;
        c = getchar();
    }
    while(c >= '0' && c <='9'){
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return f * x;
}
const int N = 5e5;
int n,k;
int a[N + 5];
int dp[1000 * 1000 + 5][2];
PLL v[1000 * 1000 + 5];
int cnt;
bool cmp(PLL a,PLL b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}


bool check(){
    for(int i = 1;i <= n;i++)
        if(a[i] > 1)
            return false;
    return true;
}
int ans;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n = read();
    k = read();
    for(int i = 1;i <= n;i++)
        a[i] = read();
    if(!check()){
        for(int i = 1;i <= n;i++){
            int x = a[i];
            if(x == k) v[++cnt] = make_pair(i,i);
            for(int j = i + 1;j <= n;j++){
                x ^= a[j];
                if(x == k)
                    v[++cnt] = make_pair(i,j);
            }
        }
        sort(v + 1,v + 1 + cnt,cmp);
        dp[0][0] = dp[0][1] = 0;
        for(int i = 1;i <= cnt;i++){
            int la = 0;
            int l = 1,r = i - 1;
            while(l <= r){
                int mid = l + r >> 1;
                if(v[mid].second < v[i].first){
                    l = mid + 1;
                    la = mid;
                }else
                    r = mid - 1;
            }
            dp[i][0] = max(dp[i - 1][1],dp[i - 1][0]);
            dp[i][1] = max(dp[la][0],dp[la][1]) + 1;
        }
        cout << max(dp[cnt][0],dp[cnt][1]) << endl;
    }else{
        if(k == 0){
            for(int i = 1;i <= n;i++){
                if(a[i] == 0){
                    ans++;
                }else{
                    int res = 0;
                    while(i <= n && a[i] == 1){
                        res++;
                        i++;
                    }
                    i--;
                    ans += res / 2;
                }
            }
        }else{
            for(int i = 1;i <= n;i++)
                if(a[i] == 1)
                    ans++;
        }
        cout << ans << endl;
    }
    return 0;
}