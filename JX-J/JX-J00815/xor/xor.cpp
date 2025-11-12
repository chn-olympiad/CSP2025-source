#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
/*
shou xian, wo men ke yi jiang k er jin zhi fen jie
ru guo man zu l dao r zai k wei 1 de wei zhi shang he wei ji shu
bing qie zai k wei 0 de wei zhi shang he wei ou shu
na mo l dao r de yi huo zhi jiu shi k
wo men ke yi yu chu li mei yi wei de qian zhui he
lai da dao O(1) cha xun l dao r zhi jian de mei yi wei de he
na mo wo men pan duan l dao r de yi huo zhi shi fou wei k jiu ke yi zai O(log) zhi nei wan cheng
zhe yang dui yu mei ge l qiu chu zui xiao de r, zai jin xing yi ge jian dan de tan xin, 60 pts
ran hou wo men ke yi zhi jie jiang tan xin de guo cheng rong ru qiu mei ge l suo dui ying de r de guo cheng zhong
zhe yang...hao ba, zui lie shi jian fu za du ren ran shi O(n ^ 2 log)

*/
int n, k;
int a[N], b[N];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = b[i - 1] ^ a[i];
    }
    int ans = 0, minl = 0;
    for(int r = 1; r <= n; r++) {
        for(int l = r; l > minl; l--) {
            if((b[r] ^ b[l - 1]) == k) {
                minl = r;
                ++ans;
                break;
            }
        }
    }
    printf("%d\n", ans);
}
