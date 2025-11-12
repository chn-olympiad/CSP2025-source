#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;
int a[1000100];
bool f = 0, ff2 = 0, ff1 = 0;
//int s[10], sa[10], sc[10];

/*void kk(int x){
    while(1){
        if(x == 0){
            break;
        }
        if(x < 2){
            s[ans--] = 1;
            break;
        }
        s[ans--] = x % 2;
        x /= 2;
        cout << s[ans];
    }

}

void ss(int y){
    while(y > 0){
        sa[cnt--] = y % 2;
        y /= 2;
    }
    for(int j = 1; j <= 8; j++){
        if(sa[j] != sc[j] && (sa[j] == 1 && sc[j] == 1)){
            sc[j] = 1;
        }
    }
    for(int j = 1; j <= 8; j++){
        if(s[j] == 0 && sc[j] == 1){
            for(int z = 1; z <= 8; z++){
                sc[z] = '0';
            }
            ff2 = 1;
        }
        if(ff2 == 1){
            break;
        }
    }
    if(ff2 != 1){
        for(int j = 1; j <= 8; j++){
            if(s[j] != sc[j]){
                ff1 = 1;
                break;
            }
        }
        if(ff1 != 1){
            sum++;
            for(int j = 1; j <= 8; j++){
                sc[j] = '0';
            }
        }
    }
}*/

int main(){

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(k == 0){
        for(int i = 1; i <= n; i++){
            if(a[i] != 1){
                f = 1;
                break;
            }
        }
        if(f != 1){
            cout << 0;
            return 0;
        }
    }
    else if(k == 1){
        for(int i = 1; i <= n; i++){
            if(a[i] == 1){
                cnt++;
            }
        }
        cout << cnt;
        return 0;
    }
    else{
        for(int i = 1; i <= n; i++){
            if(a[i] == k){
                cnt++;
            }
        }
        cout << cnt;
        return 0;
    }
}
