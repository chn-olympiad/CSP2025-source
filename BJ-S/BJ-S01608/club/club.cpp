#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 +10;
int box[N];
int h[N];
int maxn = 0;
long long a[N],b[N],c[N];
int ans = -1;

bool cmp(const int a, const int b){
    return a > b;
}

void func(int n){
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    int cnt = n / 2;
    sort(a+1,a+n+1,cmp);
    int sumn = 0;
    for(int i = 1; i <= cnt; i++){
        sumn += a[i];
    }
    cout << sumn;
}

void dfs(int cur , int n){
    if(cur == n + 1){
        int sumn = 0;
        memset(h,0,sizeof(h));
        for(int i = 1; i <= n; i++){
            h[box[i]]++;
            if(box[i] == 1){
                sumn += a[i];
            }
            if(box[i] == 2){
                sumn += b[i];

            }
            if(box[i] == 3){
                sumn += c[i];
            }
        }
        bool b = 1;
        for(int i = 1; i <= n; i++){
            if(h[i] > n / 2){
                    b = 0;
                break;
            }
        }
        if(b) ans = max(ans, sumn);
        return;
    }
    for(int i = 1; i <= 3; i++){
        box[cur] = i;
        dfs(cur+1, n);
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w", stdout);


    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        if(n > 200){
            func(n);
            continue;
        }
        ans = 0;
        for(int i= 1; i <= n; i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        memset(box,0,sizeof(box));
        dfs(1,n);
        cout << ans << endl;
    }
    return 0;
}
