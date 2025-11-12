#include<bits/stdc++.h>
using namespace std;
int n , s1 = 0 , ans = 0 , ss , cc = 0;
int a[5009] = {};
void dfs(int x , int s , int c , int ma , int aa){
    if(x > n){
        ans = max(ans , ss);
        return;
    }
    if(c > 2 * ma && ma != 0 && aa >= 3){
        ss++;
    }
    //cout << x << " " << s << " " << c << " " << ma << " " << ss << " " << aa << endl;
    dfs(x + 1 , 1 , c + a[x + 1] , max(ma , a[x + 1]) , aa + 1);
    dfs(x + 1 , 0 , c , ma , aa);
    return;
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(1 , 1 , a[1] , 0 , 1);
    dfs(1 , 0 , a[1] , 0 , 0);
    cout << ans;
	return 0;
}
