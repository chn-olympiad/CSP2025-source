#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
vector<int> v;
signed main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    n = s.length();
    s = " " + s;
    for (int i = 1; i <= n; i++){
        if (s[i] >= '0' && s[i] <= '9') v.push_back(s[i] - '0');
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i: v) cout << i;
    cout << "\n";
    return 0;
}
/*

LG UID=1419939

zen me mei you zhong wen shu ru fa, nan shou

please translate pin yin to chinese, thx (?

biao zen me diao le, xie bu liao you ji le   /ll


#define int long long  shi wo de gen!!! (?



hai shi xie yi xia ba, wu liao

csp zen me yue lai yue jian dan le

guess:

T1: red
T2: red
T3: yellow
T4: yellow

gan jue yi deng xian yao shang 350

(xia wen shi jian jun wei cai ce)

8:10  jin kao chang

8:30  kai kao, ti mian jin ran bu yong xia 30min le, zhe me niu

shi tu yong CodeBlocks + Subline shuang bian ji qi, ran hou fa xian wo zai Subline xie de dai ma zai CodeBlocks shang zhi bao cun
le yi ban, suo yi dei chong xie yi bian, shi tu yong terminal bian yi yun xing shi bai, gao de wo T1 hua le 10+ min

8:45 AC T1

8:55 AC T2

zen me zhe me shui????

gan jue shou su bian man le, zen me hui shi ne

8:55 kai T3, gan jue shi tan xin, bu hui, tiao

9:10 ~~bai le yi hui~~ ran hou kai T4, ran hou yi shi dao shi dp

9:35 AC T4

hui qu kan T3, yan jiu le yi xia jiu hui le

10:20 AC T3

zen me zhe me shui zen me zhe me shui zen me zhe me shui zen me zhe me shui zen me zhe me shui zen me zhe me shui zen me zhe me shui

xia wu S bu hui ye zhe me shui ba /yiw

kai bai!!!!



hai shi dui pai ba, wo bu xiang si qwq


gan jue wo hao tang qwq


//freopen("number.in", "r", stdin);
//freopen("number.out", "w", stdout);

*/
