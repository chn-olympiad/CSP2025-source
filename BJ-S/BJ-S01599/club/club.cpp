#include <bits/stdc++.h>
using namespace std;
int ans , n , t;
vector<int> ans_sum;
struct people{
    int x;
    int y;
    int z;
} a[100100];
void dfs(int u , int sumx , int sumy , int sumz , int ansx , int ansy , int ansz){
    if(u > n){
        if(ansx > (n / 2) || ansy > (n / 2) || ansz > (n / 2)){
            return ;
        }else{
            ans_sum.push_back(sumx + sumy + sumz);
        }
        return ;
    }
    dfs(u + 1 , sumx + a[u].x , sumy , sumz , ansx + 1 , ansy , ansz);
    dfs(u + 1 , sumx , sumy + a[u].y , sumz , ansx , ansy + 1 , ansz);
    dfs(u + 1 , sumx , sumy , sumz + a[u].z , ansx , ansy , ansz + 1);
}
int main(){
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    cin >> t;
    while(t --){
        cin >> n;
        for(int i = 1;i <= n;i ++){
            cin >> a[i].x >> a[i].y >> a[i].z;
        }
        dfs(1 , 0 , 0 , 0 , 0 , 0 , 0);
        sort(ans_sum.rbegin() , ans_sum.rend());
        cout << ans_sum[0] << endl;
        ans = 0;
        for(int i = 0;i <= n;i ++){
            a[i].x = 0;
            a[i].y = 0;
            a[i].z = 0;
        }
        while(!ans_sum.empty()){
            ans_sum.pop_back();
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}