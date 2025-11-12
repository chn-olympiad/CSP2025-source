#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int x[N],n,k;
bool a = 1,b = 1,c = 1;
int main (){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n ;i++){
        cin >> x[i];
        if (x[i] != 1)a = 0;
        if (x[i] > 1)b = 0;
        if (x[i] > 255)c = 0;
    }if (a){
        cout << n/2;
    }else if (b){
        if (k == 1){
            int ocnt = 0;
            for (int i = 1; i <= n; i++){
                if (x[i] == 1)ocnt++;
            }
            cout << ocnt;
        }else{
            int ocnt = 0,zcnt = 0;
            for (int i = 1; i <= n; i++){
                if (x[i] == 1 && x[i+1] == 1)ocnt++;
                if (x[i] == 0)zcnt++;
            }cout << ocnt+zcnt;
        }
    }else if(c){
        int sum = 0;
        for (int i = 1; i <= n; i++){
            sum+=x[i];
        }cout << sum/k;
    }
    return 0;
}
