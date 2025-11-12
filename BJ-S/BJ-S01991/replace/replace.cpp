#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
struct replace{
    string s1,s2;
}a[200005];
int main(){
    //第一次打了个freopen("raplace.in","r",stdin);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++){
        cin >> a[i].s1 >> a[i].s2;
    }
    while (q--){
        string t1,t2;
        cin >> t1 >> t2;
        int ans = 0;
        for (int j = 1;j <= n;j++){
            int pos = t1.find(a[j].s1);
            while (pos != -1){
                string s = t1;
                s.replace(pos,a[j].s1.size(),a[j].s2);
                if (s == t2) ans++;
                pos = t1.find(a[j].s1,pos + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
//16:45开T3，开局想到KMP，然后发现数太大……突然发现自己连KMP都忘了……我是不是成**了……
//17:00老师宣告“还有3个人一道题都没交，17:30的时候再不交一题就点名了。还有5个人只交了一题”
//17:40扔了T4看T3，还是写个暴力吧
//说句心里话，这次CSPS完全是试一下，但是感觉那500多白扔了……
//不用祝好，反正就是试一下，又没打算拿6级勾虽说那玩意现在人手一个我橙名了还没有有点不正常
//咕值屁用没有   ——chen_zhe
//18:00老师说还有3个人只交了一题，有一个尾号0052，还有一个1748
//18:11不小心把文件回收系统给退了
//18:15不小心又把文件回收系统给退了