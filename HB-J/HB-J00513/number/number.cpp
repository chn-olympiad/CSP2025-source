#include<bits/stdc++.h>
using namespace std;
int t[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++){
        int a = int(s[i] - '0');
        if(a >= 0 && a <= 9){
            t[a]++;
        }
    }
    for(int i = 9;i >= 0;i--){
        for(int j = 1;j <= t[i];j++){
            printf("%d",i);
        }
    }
}
