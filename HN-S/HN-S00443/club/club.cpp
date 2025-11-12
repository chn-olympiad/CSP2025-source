#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int t, n, a[N][3], id[N], cnt[3], ned;
int v[N], len, ans;
inline int dif(int f, int i){
    int mx=0;
    for(int j=0;j<3;j++) if (i!=j) mx=max(mx,a[f][j]);
    return a[f][i] - mx;
}
bool cmp(int a, int b){
    return dif(a,ned) < dif(b,ned);
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    while(t--){
        memset(cnt, 0, sizeof cnt);
        len = ans = 0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
        for(int i=1;i<=n;i++){
            int j = 0;
            for(int k=1;k<=2;k++)
                if (a[i][k] > a[i][j] || (a[i][k]==a[i][j] && cnt[k]<cnt[j])) j=k;
            cnt[j]++;
            id[i] = j;
            ans += a[i][j];
        }
        for(int iu=0;iu<3;iu++){
            if (cnt[iu] <= n/2) continue;
            ned = iu;
            for(int i=1;i<=n;i++){
                if (id[i] == iu) v[++len] = i;
            }
            sort(v+1, v+len+1, cmp);
            for(int i=1;i<=len-n/2;i++) ans -= dif(v[i], iu);
            break;
        }
        cout << ans << '\n';
    }
}
