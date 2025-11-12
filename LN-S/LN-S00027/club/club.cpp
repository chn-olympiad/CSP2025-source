#include <bits/stdc++.h>
using namespace std;
struct item {
    int a,b,c;
}is[100010];
bool cmp2(item a,item b) {
    int Ma=max(a.a,max(a.b,a.c)),Mb=max(b.a,max(b.b,b.c));
    long long da=0x3f3f3f3f3f3f3f3f,db=0x3f3f3f3f3f3f3f3f;
    if (Ma == a.a) da = min(Ma - a.b,Ma - a.c);
    else if (Ma == a.b) da = min(Ma - a.a,Ma - a.c);
    else da = min(Ma - a.a,Ma - a.b);
    if (Mb == b.a) db = min(Mb - b.b,Mb - b.c);
    else if (Mb == b.b) db = min(Mb - b.a,Mb - b.c);
    else db = min(Mb - b.a,Mb - b.b);
    return da < db;
}
int n;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int _;
    cin >> _;
    while (_--) {
        cin >> n;
        for (int i=1;i<=n;i++) cin >> is[i].a >> is[i].b >> is[i].c;
        sort (is+1,is+1+n,cmp2);
        long long sum=0;
        int cnt1=0,cnt2=0,cnt3=0;
        for (int i=1;i<=n;i++) {
            if (is[i].a>=max(is[i].b,is[i].c)) sum += is[i].a,cnt1++;
            else if (is[i].b>=max(is[i].a,is[i].c)) sum += is[i].b,cnt2++;
            else sum += is[i].c,cnt3++;
        }
        if (cnt1>n/2) {
            int u=cnt1-n/2;
            for (int i=1;i<=n;i++) {
                if (!u) break;
                if (is[i].a>=max(is[i].b,is[i].c)) {
                    sum -= is[i].a-max(is[i].b,is[i].c),u--;
                }
            }
        } else if (cnt2>n/2) {
            int u=cnt2-n/2;
            for (int i=1;i<=n;i++) {
                if (!u) break;
                if (is[i].b>=max(is[i].a,is[i].c)) {
                    sum -= is[i].b-max(is[i].a,is[i].c),u--;
                }
            }
        } else if (cnt3>n/2) {
            int u=cnt3-n/2;
            for (int i=1;i<=n;i++) {
                if (!u) break;
                if (is[i].c>=max(is[i].a,is[i].b)) {
                    sum -= is[i].c-max(is[i].a,is[i].b),u--;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
