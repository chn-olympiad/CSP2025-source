#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 10;
int a[N],cnt;
string s;
bool cmp(int a,int b){
    return a > b;
}
int32_t main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < (int)s.size();i++){
        if(isdigit(s[i])){
            a[++cnt] = (s[i] - '0');
        }
    }
    sort(a + 1,a + cnt + 1,cmp);
    for(int i = 1;i <= cnt;++i){
        printf("%lld",a[i]);
    }
    return 0;
}
