#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
string a;
int num[1000005], cnt;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> a;
    for(int i = 0; i < a.size(); i++){
        if(int(a[i]) >= 48 && int(a[i]) <= 57){
            num[cnt++] = (int(a[i]) - 48);
        }
    }
    sort(num, num + cnt, cmp);
    for(int i = 0; i < cnt; i++) cout << num[i];
    return 0;
}
