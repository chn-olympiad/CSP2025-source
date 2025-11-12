#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T , n , ans;
struct tai_du{
    ll u , v , z;
}member[10010];
void dfs(ll now , ll sum , ll a , ll b , ll c){
    if(now > n){
        if(a <= n/2 && b <= n/2 && c <= n/2){
            ans = max(ans , sum);
        }
        return ;
    }
    dfs(now+1 , sum + member[now].u , a+1 , b , c);
    dfs(now+1 , sum + member[now].v , a , b+1 , c);
    dfs(now+1 , sum + member[now].z , a , b , c+1);
}
int main(){

    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);

    cin >> T;
    while(T--){
        cin >> n;
        ans = 0;
        for(int i = 1;i <= n;i++){
            cin >> member[i].u >> member[i].v >> member[i].z;
        }
        dfs(1 , 0 , 0 , 0 , 0);
        cout << ans << endl;
    }






    return 0;
}
