#include<bits/stdc++.h>
#define debug(x) cout << x << " ";
using namespace std;
const int MAXN = 1e5 + 5;
long long ans = 0;
long long daan=0;
int n;
int remain[3];
struct Student{
    int s[3];
}a[MAXN];
void dfs(int x){
    if(x>=n){
        if(ans > daan){
            daan = ans;
        }
        return;
    }
    for(int i=0;i<3;i++){
        if(remain[i]){
            ans += a[x].s[i];
            remain[i] --;
            dfs(x+1);
            ans -= a[x].s[i];
            remain[i] ++;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("club.in","r",stdin);
    int t;
    cin >> t;
    while(t--){
        ans = 0;
        daan = 0;
        cin >> n;
        for(int i=0;i<3;i++)
            remain[i] = n/2;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin >> a[i].s[j];
            }
        }
        dfs(0);
        cout << daan << "\n";
    }
    return 0;
}
