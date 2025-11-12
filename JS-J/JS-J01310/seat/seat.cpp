#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 110;

int n, m, s;
int a[N];

bool cmp(int a1, int a2){
    return a1 > a2;
}

void init(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    s = a[1];
    sort(a + 1, a + n * m + 1, cmp);
}

void solve(){
    for(int i = 1, c = 1, r = 1; i <= n * m; i++){
        //cout << "c, r:" << c << " " << r << endl;
        if(s == a[i]){
            cout << c << " " << r << '\n';
            break;
        }
        if(c % 2 == 0){
            if(r == 1)
                c++;
            else
                r--;
        }
        else{
            if(r == n)
                c++;
            else
                r++;
        }
    }
}

void close(){
    fclose(stdin);
    fclose(stdout);
}

int main(){
    init();
    solve();
    close();
    return 0;
}
