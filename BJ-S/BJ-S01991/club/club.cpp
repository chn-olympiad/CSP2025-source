//我是从第二题开始做的
//做了1.5小时无果，跳到第一题了

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
//先Never Gonna Give You Up制人
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
//freopen("//freopen("//freopen("//freopen("//freopen("
// #include #include #include #include #include #include
// #include #include #include #include #include #include
// #include #include #include #include #include #include
// #include #include #include #include #include #include
// #include #include #include #include #include #include
// #include #include #include #include #include #include
// #include #include #include #include #include #include
// #include #include #include #include #include #include
// #include #include #include #include #include #include
//orz sto orz sto orz sto orz sto orz sto orz sto orz sto
//orz sto orz sto orz sto orz sto orz sto orz sto orz sto
//orz sto orz sto orz sto orz sto orz sto orz sto orz sto
//orz sto orz sto orz sto orz sto orz sto orz sto orz sto
//orz sto orz sto orz sto orz sto orz sto orz sto orz sto
//orz sto orz sto orz sto orz sto orz sto orz sto orz sto
//orz sto orz sto orz sto orz sto orz sto orz sto orz sto
//slove slove slove slove slove slove slove slove slove
//slove slove slove slove slove slove slove slove slove
//slove slove slove slove slove slove slove slove slove
//slove slove slove slove slove slove slove slove slove
//slove slove slove slove slove slove slove slove slove
using namespace std;
int input(){
    char ch;
    while (!isdigit(ch = getchar_unlocked()));
    int ret = ch ^ 48;
    while (isdigit(ch = getchar_unlocked())) ret = (ret << 3) + (ret << 1) + (ch ^ 48);
    return ret;
}
//祖传开不开O2都这么写的快读
struct node{
    int a,b,c;
}a[300005];
bool flag[100005];
bool cmp(node x,node y){
    return x.a > y.a;
}
void solve(){
    memset(a,0,sizeof a);
    memset(flag,0,sizeof flag);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++){
        int _a = input();
        int b = input();
        int c = input();
        a[3 * i - 2] = {_a,1,i};
        a[3 * i - 1] = {b,2,i};
        a[3 * i - 0] = {c,3,i};
    }
    sort(a + 1,a + 3 * n + 1,cmp);
    int b[4] = {0,0,0,0},ans = 0;
    for (int i = 1;i <= 3 * n;i++){
        if (b[a[i].b] == n / 2 || flag[a[i].c]) continue;
        b[a[i].b]++;
        flag[a[i].c] = true;
        ans += a[i].a;
    }
    cout << ans << endl;
    //发现这个贪心有瑕疵，但是这已经是我的极限了 16:24
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t = input();
    while (t--) solve();
    return 0;
}
//我的电脑屏幕上有一个像素点坏了，只能显示绿色，对于有强迫症的我来说非常不友好