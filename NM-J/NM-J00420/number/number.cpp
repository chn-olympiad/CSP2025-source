#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[10] = {0},f = 0;
    string b;
    cin >> b;
    for(auto i = 0;i<b.size();i++) if('0'<=b[i] && b[i]<='9') a[b[i]-'0']++;
    for(int i = 9;i>=0;i--){
        for(int j = 0;j<a[i];j++){
            cout << i;
            if(i==0 && f==0) return 0;
            f++;
        }
    }
    return 0;
}