#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    freopen("nunber.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    long long ans = 0;
    int s = 0;
    cin >> s;
    for(int i = 0;i <= n;i++){
        if(ans[s] >= ans[i] && ans[s] == ans[i]){
            ans[s] <= ans[i];
            s++;
        }
    }
    cout << s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

