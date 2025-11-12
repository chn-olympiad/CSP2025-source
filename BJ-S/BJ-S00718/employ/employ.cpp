#include <bits/stdc++.h>
using namespace std;

/*
  一转眼就上高三了，这是我最后一次坐在 csp 考场上了吧。
  这段时间都没怎么碰 oi 了，反正 csp 的分数对我也没什么用处了，我坐在这里仅仅是为了能去打 noip 而已。
  考场上有个逆天小登一直吵……好烦人……
  为啥我还要打 noip 呢？大概是之前觉得对申请 hku 有帮助吧。
  为啥我当初想要申 hku 呢？因为我喜欢过去了那里的一个学姐……
  她已经是别人的女朋友了。（原因还是吴孟 w6 要发女朋友这种开玩笑一样的事）
  所以说，我为什么还要在这里？
  可能是所谓的热爱吧。
  时间已所剩无几，没时间把心中的感触都讲完了。
  祝你天天开心，陌生人。
  也祝他们幸福。
  CC__DIAMOND
*/


namespace Solution {
    constexpr int MAX_N = 510;
    int n,m;
    char s[MAX_N];
    int c[MAX_N];
    void solve() {
        cin>>n>>m;
        cin>>s+1;
        for(int i=1;i<=n;++i) s[i]-='0';
        for(int i=1;i<=n;++i) cin>>c[i];
        sort(c+1,c+n+1);
        ll x = 1;
        ll ans  =0;
        for(int i=1;i<=n;++i) x*=i;
        for(int i=1;i<=x;++i) {
            int cnt = 0,f = 0;
            if(f>=c[i]||s[i]==0) {
                f++;
            } else {
                cnt++;
            }
            next_permutation(c+1,c+n+1);
            if(cnt>=m) ans++;
        }
        cout<<ans<<'\n';
    }
}

int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    for(int t=1;t<=T;++t) {
        Solution::solve();
    }
    return 0;
}