#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int n,m,ans;
int c[N],step[N];
bool d[N];
string s,st;

void f(int k){
    if(k == n + 1){
        for(int i = 1;i<=n;i++) cout << step[i] <<" ";
        cout << endl;
        int cnt = 0,person = 0;
        for(int i = 1;i<=n;i++){
            if(cnt > c[step[i]]) continue;
            if(s[i - 1] == '1') person++;
            else cnt++;
        }
        if(person >= m) ans++;
        return;
    }

    for(int i = 1;i<=n;i++){
        if(d[i] == false){
            d[i] = true;
            step[k] = i;
            f(k + 1);
            d[i] = false;
        }
    }
    return;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1;i<=n;i++) cin >> c[i];
    f(1);
    cout << (ans % 988244353);
    return 0;
}
