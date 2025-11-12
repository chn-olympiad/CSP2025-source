#include<bits/stdc++.h>
using namespace std;

int a[1000005] , cnt = 0;

int main(){
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);

    string s;
    cin >> s;

    int n = s.size();
    for(int i = 0 ; i < n ; i ++){
        if(isdigit(s[i])){
            cnt ++;
            a[cnt] = s[i] - 48;
        }
    }

    sort(a + 1 , a + cnt + 1);

    for(int i = cnt ; i >= 1 ; i --){
        cout << a[i];
    }
    return 0;
}
