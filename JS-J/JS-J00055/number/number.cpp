#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 5;
int num[MAX_N];

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int len = s.size();
    int top = 0;
    for(int i = 0;i < len;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num[top] = s[i] - '0';
            top++;
        }
    }
    sort(num, num + top);
    for(int i = top - 1;i >= 0;i--){
        printf("%d", num[i]);
    }
    return 0;
}
