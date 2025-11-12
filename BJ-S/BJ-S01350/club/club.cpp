#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::sort;
// #define DEBUG
#ifdef DEBUG
#define debug printf
#else
#define debug(...)
#endif // DEBUG
void solve() {
    int n;
    cin >> n;
    const int m = n>>1;
    int a[n][3];
    int cnt[3] = {0,0,0};
    int mxVal[n], mxId[n];
    int ans = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        int id=0, val=a[i][0];
        if(a[i][1] > val) id=1, val=a[i][1];
        if(a[i][2] > val) id=2, val=a[i][2];
        mxVal[i] = val;
        mxId[i] = id;
        // mx[n].i = i;
        cnt[id]++;
        ans += val;
    }
    //for(int i=0; i<n; i++) {
    //    debug("a[%d]: %d %d %d\n", i, a[i][0], a[i][1], a[i][2]);
    //}
    debug("cnts: %d %d %d\n", cnt[0], cnt[1], cnt[2]);
    for(int i=0; i<n; i++) debug("%d ", mxId[i]); debug("\n");
    for(int i=0; i<n; i++) debug("%d ", mxVal[i]); debug("\n");
    int id=-1;
    if(cnt[0] > m) id=0;
    if(cnt[1] > m) id=1;
    if(cnt[2] > m) id=2;
    if(id < 0) {
        cout << ans << "\n";
        return;
    }
    debug("out-of-range: %d\n", id);
    debug("now answer: %d\n", ans);
    int diff[cnt[id]]; int _ID=0;
    for(int i=0; i<n; i++) {
        if(mxId[i] == id) {
            int m = -1;
            if(id!=0 && a[i][0]>m) m=a[i][0];
            if(id!=1 && a[i][1]>m) m=a[i][1];
            if(id!=2 && a[i][2]>m) m=a[i][2];
            diff[_ID++] = mxVal[i] - m;
        }
    }
    sort(diff, diff+cnt[id]);
    debug("diff[%d]: ", cnt[id]);
    for(int i=0; i<cnt[id]; i++) debug("%d ", diff[i]);
    debug("\n");
    //for(int i=cnt[id]-1; i>=m; i--) {
    for(int i=0; i+m<cnt[id]; i++) {
        debug("deleting#%d: ans-=%d -> %d\n", i, diff[i], ans-diff[i]);;
        ans -= diff[i];
    }
    cout << ans << "\n";
}
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        if(i) debug("\n==========\n\n");
        solve();
    }
    return 0;
}
