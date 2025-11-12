#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    vector<int> lis(12);
    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){
           lis[s[i] - '0']++;
        }
    }
    for(int i = 9; i >= 0; i--){
        while(lis[i]){
            printf("%d", i);
            lis[i]--;
        }
    }
    return 0;
}
