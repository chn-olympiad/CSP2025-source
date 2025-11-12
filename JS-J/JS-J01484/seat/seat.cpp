#include <bits/stdc++.h>
using namespace std;
int a[15][15],s[105];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++) cin >> s[i];
    int s1 = s[1];
    sort(s + 1,s + n * m + 1,cmp);
    int num = 0;
    for (int j = 1;j <= m;j++){
        if (j % 2 == 1){
            for (int i = 1;i <= n;i++){
                num++;
                a[i][j] = s[num];
                if (s[num] == s1){
                    cout << j << " " << i;
                    return 0;
                }
            }
        }else{
            for (int i = n;i >= 1;i--){
                num++;
                a[i][j] = s[num];
                if (s[num] == s1){
                    cout << j << " " << i;
                    return 0;
                }
            }
        }
    }
    return 0;
}
