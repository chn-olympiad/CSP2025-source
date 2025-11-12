#include<bits/stdc++.h>
using namespace std;

long long a[500010];

struct qj{
    long long l;
    long long r;
};

qj ans[50000010];

bool cmp(qj x, qj y){
    if (x.r == y.r) return x.l > y.l;
    return x.r < y.r;
}

int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    long long n,k;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) cin >> a[i];

    long long f = 0;

    for (long long i = 1; i <= n; i++){
        long long res = 0;
        for (long long j = i; j <= n; j++){
            res = res^a[j];
            if (res == k){
                f++;
                ans[f].l = i;
                ans[f].r = j;
            }
        }
    }

    sort(ans+1,ans+f+1,cmp);

    //for (int i = 1; i <= f; i++) cout << ans[i].l << " " << ans[i].r << endl;

    long long res = 0,w = 0;
    for (long long i = 1; i <= f; i++){
        if (ans[i].r > ans[i-1].r && w < ans[i].l){
            res++;
            w = ans[i].r;
        }
    }

    cout << res;

    return 0;
}
