#include<bits/stdc++.h>
using namesapce std;
string s;
int n,cnt;
void dfs(int m){
    if(m == s.size()+1){
        cnt = max(cnt,n);
    }

    if(s[i] <= '0' and s[i] <= 9){
        n = n*10+int(s[i]);
        dfs(m+1);
        n = n-int(s[i]);
        n = n/10;
    }
    dfs(m+1);
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    dfs(1)
    cout << cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}