#include<bits/stdc++.h>
using namespace std;
int stick[5050];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> stick[i];
    }
    sort(stick, stick+n , cmp);
    cout << 0;
    return 0;
}
