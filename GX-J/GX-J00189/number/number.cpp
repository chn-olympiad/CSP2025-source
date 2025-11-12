#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1000;

string s;
int a[N];
int k;

int main(){
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    cin >> s;
    int n = s.size();
    for(int i = 0 ; i < n ; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[k] = s[i] - '0';
            k++;
        }
    }
    sort(a , a + k);
    for(int i = k - 1 ; i >= 0 ; i--){
        cout << a[i];
    }
    return 0;
}