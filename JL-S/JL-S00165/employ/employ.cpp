#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
string s;
int fail;
int cnt;
int a[N], b[N], bk[N], diff[N];
void dfs(int x){
    if(x > n){
        for(int i = 1; i <= n; i++){
            if(a[i] - diff[i] > 0) cnt ++;
            else diff ++;
        }
        diff = 0;
        return ;
    }
    for(int i = 1; i <=n ;i ++)
    {
        if(!bk[i]){
            a[x] = b[i];
            bk[i] = 1;
            dfs(x + 1);
            bk[i] = 0;
        }
    }
}
int main(){
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < s.size(); i ++){
        diff[i + 1] = (int)(s[i]-'0');
    }
    for(int i = 1; i <= n; i ++){
        cin >> b[i];
    }
    dfs(1);
    cout << cnt;
    return 0;
}
