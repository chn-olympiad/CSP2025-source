#include <bits/stdc++.h>
using namespace std;
// h 60pts TLE

const long long MAXN=5e5+10;
long long n, a[MAXN], summ[MAXN], k, idx, ans;
struct qu{
    long long s, e, bl;
}q[MAXN*10];

bool cmp(qu a, qu b){
    return a.bl>b.bl;
}

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        summ[i]=a[i]^summ[i-1];
        // printf("[%d]%lld\n", i, summ[i]);
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            long long t; t=summ[j]^summ[i-1];
            // printf("[%d,%d]%lld\n", i, j, t);
            if (t==k){
                q[idx].s=i; q[idx].e=j;
                idx++;
            }
        }
    }
    ans=idx;
    long long bla=0, blt=0;
    for (int i=0;i<idx;i++){
        for (int j=0;j<i;j++){
            if ((q[i].e>=q[j].s&&q[i].e<=q[j].e)||(q[i].s>=q[j].s&&q[i].s<=q[j].e)){
                q[i].bl++;
                q[j].bl++;
                bla+=2;
            }
        }
    }
    sort(q, q+idx, cmp);
    for (int i=0;i<idx;i++){
        if (blt*2>=bla) break;
        blt+=q[i].bl;
        // printf("%lld %lld\n", q[i].bl, bla);
        ans--;
    }
    cout<<ans<<endl;
    return 0;
}

