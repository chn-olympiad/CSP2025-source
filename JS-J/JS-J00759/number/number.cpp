#include<bits/stdc++.h>
using namespace std;
long long len , l = 0;
priority_queue<int> a;
int main(){
    //("number.in" , "r" , stdin);
    //freopen("number.out" , "w" , stdout);
    string s;
    cin >> s;
    len = s.size();
    for(int i = 0 ; i < len ; i ++){
        if(s[i] >= '0' && s[i] <= '9'){
            a.push(s[i] - '0');
            l ++;
        }
    }
    for(int i = 1 ; i <= l ; i ++){
        cout << a.top();
        a.pop();
    }
    return 0;
}
