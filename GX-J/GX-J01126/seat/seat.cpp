#include <bits/stdc++.h>
#include <string>
using namespace std;
bool cmp(int x,int y){
    x > y;
}
int main(){
    string s;
    int n,m,c = 1,r = 1;
    cin >> n >> m;
    sort(s[0],s[n*m],cmp);
    for(int i = 0;i <= n*m - 1;i++){
        cin >> s[i];
        for(int j = c;j <= m;j++){
            for(int k = r;k <= n;k++){
                if(s[0] == s[i])
                    cout << c << r;
                else
                    continue;
            }
        }
    }
    return 0;
}
