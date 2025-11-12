#include<bits/stdc++.h>
using namespace std;
#define int long long

int t,n,a[100010][5],c1,c2,c3,an[100010],ans;

int read(){
    char c;
    int k = 0,f = 1;
    c = getchar_unlocked();
    while(c > '9' || c < '0'){
        if(c == '-'){
            f = -1;
        }
        c = getchar_unlocked();
    }
    while('0' <= c && c <= '9'){
        k = k * 10 + c - '0';
        c = getchar_unlocked();
    }
    return k * f;
}

void solve(int type){
    int c;
    if(type == 1){
        c = c1;
    }else if(type == 2){
        c = c2;
    }else{
        c = c3;
    }
    multiset<int> s;
    s.clear();
    for(int i = 1;i <= n;i++){
        if(an[i] == type){
            s.insert(min(a[i][type] - a[i][type % 3 + 1],a[i][type] - a[i][(type + 1) % 3 + 1]));
        }
    }
    for(auto i : s){
        if(c <= n / 2){
            break;
        }
        ans -= i;
        c--;
    }
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin >> t;

    while(t--){
        cin >> n;
        c1 = c2 = c3 = ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 3;j++){
                cin >> a[i][j];
            }
            if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
                c1++;
                an[i] = 1;
            }else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
                c2++;
                an[i] = 2;
            }else{
                c3++;
                an[i] = 3;
            }
            ans += a[i][an[i]];
//            cout << an[i] << " ";
        }
//        cout << endl;
//        cout << c1 << ' ' << c2 << ' ' << c3 << endl;
        if(c1 > n / 2){
            solve(1);
        }else if(c2 > n / 2){
            solve(2);
        }else if(c3 > n / 2){
            solve(3);
        }
        cout << ans << endl;
    }

    return 0;
}