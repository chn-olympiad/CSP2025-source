#include<bits/stdc++.h>
using namespace std;
int s[10000],ans;
int main(){
    feopen("employ.in","r",stdin)
    feopen("employ.out","w",stdout)
    int n,m,k;cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> s[i];
    int k = m + 1;
    while(t < n+m){
        for(int i = 1;i <= n;i++){
            s[i]--;
            if(s[i] == 0){
                s[i] = s[k];
                j++;
            }
        }
        ans++;
    }
    cout << ans;
    return 0;
}
