/*
17：12 开T3，有点偏晚了。

但是剩下一个小时都是T3的，既决生死，也分高下。

顺便吐槽一句：

鹰角给我加强溯光星源！！！！！！

16%的脆弱和25%的传导伤害算**什么！！！！！！

赠送六星不是给你这么霍霍的！！！！！这还是我们家星源宝（可能）唯一的一次异格机会啊啊啊啊啊啊啊啊！！！！！

鹰角你坏事做尽！！！！！

唯一可能能期待的也就只有星极异格了，唉，我们乌比卡家。

===============================分隔符==================================

只有暴力可以打了说是，kmp什么的早就忘掉了啊。

可是我连字符串的函数都不会用啊...... 17：18

拿c++自带的函数写了一份，毕竟真想不到别的做法。

不是宝宝你怎么两份数据都输出 0 啊？！我要狠狠的调试你了哦！！！ 17：33

破案了，string.replace() 会修改原字符串。

小数据过了，大数据没得测。还是玩小恐龙吧。17：41
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 220000;
int n, q, ans;
pair<string, string> s[N];
string s1, s2;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> s1 >> s2, s[i] = {s1, s2};
    for(int i = 1; i <= q; i++) {
        cin >> s1 >> s2;
        ans = 0;
        for(int id = 1; id <= n; id++){
            for(int l = 0; l + s[id].first.length() <= s1.length(); l++){
                string sub_s1 = s1.substr(l, s[id].first.length());
                //cout << sub_s1 << ' ';
                if(sub_s1 != s[id].first) { /*cout << '\n';*/ continue; }
                string s_tmp = s1;
                string s_replace = s_tmp.replace(l, s[id].first.length(), s[id].second);
                //cout << s_replace << '\n';
                if(s_replace == s2) ans++;
            }
        }
        cout << ans << '\n';
    }
    cout << flush;
}
