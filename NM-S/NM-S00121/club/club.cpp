#include<bits/stdc++.h>
using namespace std;
int t;
int n ;
int a[31][4];
int fl[4];
int h[31];
int ans;
int ans1;
void dfs(int x){
    for(int i = 1; i <= 3; i++)
        if(fl[i] > n/2)
            return;
    if(x > n){
    ans1 = max(ans,ans1);
    return;
    }
    for(int i = 1; i <= n; i++){
        if(!h[i]){
            for(int j = 1; j <= 3; i++){
                ans += a[i][j];
                h[i] = 1;
                fl[j]++;
                dfs(x+1);
                fl[j]--;
                h[i] = 0;
                ans -= a[i][j];
            }
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >>t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        ans = 0;
        ans1 = 0;
        memset(h,0,sizeof(h));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= 3; j++)
                cin >>a[i][j];
        dfs(1);
        cout <<ans1 << endl;
    }
    return 0;
}
