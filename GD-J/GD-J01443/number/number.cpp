#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 15;
string s;
int a[N],cnt;
bool cmp(int x,int y){
    return x > y;
}
int main(){
//    freopen("number3.in","r",stdin);
//    freopen("number.txt","w",stdout);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    for(int i = 0;i < s.size();i ++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[++ cnt] = (int)(s[i] - '0');
        }
    }
    sort(a + 1,a + 1 + cnt,cmp);
    for(int i = 1;i <= cnt;i ++){
        cout << a[i];
    }
    return 0;
}
