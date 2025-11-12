#include<bits/stdc++.h>
// 没什么大不了
using namespace std;
// 于是砸了染缸
namespace hyh {
    struct ovo {
        int a, b, c;
    };
    bool cmpa(ovo x, ovo y) {
        return x.a > y.a;
    }
    bool cmpb(ovo x, ovo y) {
        return x.b > y.b;
    }
    bool cmpc(ovo x, ovo y) {
        return x.c > y.c;
    }
    // ccf你要让我S < 100分离场吗 你是入啊
    // 我afoafoafo
    // 
    int vis[100005];
    void solve() {
        int n;
        int cnt1, cnt2, cnt3;
        cnt1 = cnt2 = cnt3;
        cin >> n;
        int p = n / 2;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x) v.push_back(x);
            cin >> x;
            if (x) v.push_back(x);
            cin >> x;
            if (x) v.push_back(x);
        }
        int ans = 0;
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (int i = 0; i < p; i++) {
            ans += v[i];
        }
        cout << ans << "\n";
    }
    /*
    那年光阴太漫长
    那年风声太张狂

    朝霞随春去，余暇伴夏来

    总要迈出这一步的
    不是吗
    都一样的

    既然你我都在这段旅途上
    这段路不妨结伴而行
    
    在那之前
    你要多想
    */
    signed main() {
        freopen("club.in", "r", stdin);
        freopen("club.out", "w", stdout);
        int _test_ = 1;
        cin >> _test_;
        while (_test_--) {
            solve();
        }
        return 0;
    }
}
/*
10
2020 14533 18961 √
2423 15344 16322 √
1910 6224 16178  ×
2038 9963 19722  √
8375 10557 5444 ×
3518 14615 17976 √
6188 13424 16615 √
8769 509 4394 1
958 3195 9953 1
16441 5313 10926 ×
 
*/
/*
他们说
就让他们去说
生命如长风
吹过谁的心头
你想被记住
的那个名字
将会是什么

cos i was afraid 
was alone
in a cage
like a stone

丹青千秋酿
一醉解惆怅

你说你不想在这里
我也不想在这里
可天黑的太快想走早就来不及

你来过
然后你走后
只留下星空

那一天我们望着星空
有那么多的灿烂的梦
*/



//wc我怎么要包0了
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return hyh::main();
}
//the dance was so dangerous
//we must to change us 
//like hermit
//use to find the reason to not to be
//you teach    
// 我精神分裂严重
// ccf你要让我S < 100分离场吗 你是入啊
// 我afoafoafo