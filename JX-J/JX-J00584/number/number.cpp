#include <bits/stdc++.h>
using namespace std;
string s;
int n,sum = 0;
int b[10000001];
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    n =sizeof(s);
    for(int i = 0;i < n;i++){
        if(s[i] - '0' <= 9 && s[i] - '0' >= 0){
            b[sum] = s[i] - '0';
            sum++;
        }
    }
    sort(b,b+sum,cmp);
    for(int i = 0;i < sum;i++){
        if(b[i] >= 0){
            cout << b[i];
        }
    }
    return 0;
}
