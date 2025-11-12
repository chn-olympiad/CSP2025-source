#include<bits/stdc++.h>
using namespace std;
int a[11];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin>>s;
    for(int i = 0;i < s.size();i++){
        int u = s[i] -'0';
        if(u >= 0 && u <= 9) a[u]++;
    }
    for(int i = 9;i >= 0;i--){
        for(int j = a[i];j > 0;j--){
            cout << i;
        }
    }
    return 0;
}

