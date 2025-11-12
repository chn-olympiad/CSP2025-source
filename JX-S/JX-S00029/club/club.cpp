#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct u{
    int a,b,c;
    double d;
}a[N];

bool cmp(u a , u b) {
    return a.d < b.d;
}

int cnt[N];

int main() {
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    int t;
    cin>>t;
    while(t --) {
        int n;
        cin>>n;
        long long ans = 0;
        for (int i=1;i<=n;i++) {
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].d = (a[i].a + a[i].b + a[i].c) / 3.0;
        }
        sort(a + 1 , a + n + 1 , cmp);
       for (int i=1;i<=n;i++) {
            int p;
            p = max(max(a[i].a , a[i].b) , a[i].c);
            if (a[i].a == p) {
                cnt[1] ++;
            }else if (a[i].b == p) {
                cnt[2] ++;
            }else {
                cnt[3] ++;
            }
            ans += p;
       }
       cout<<ans<<"\n";
    }
    return 0;
}
