#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int s_len = s.length();
    int tong[10] = {0};
    for(int i = 0;i < s_len;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            tong[s[i] - '0'] += 1;
        }
    }
    for(int i = 9;i >= 0;i--){
        for(int j = 0;j < tong[i];j++){
            cout << i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
