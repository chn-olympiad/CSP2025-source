#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e5 + 5;

int T,n;
struct node{
    ll x,y,z;
}a[MAX];
ll msm[MAX],ans;

void solve1(){
    for(int i = n;i >= 1;i--)
            msm[i] = msm[i + 1] + std::max({a[i].x,a[i].y,a[i].z});
    int maxa = n / 2;
    auto dfs = [&](auto &dfs,int d,int c1,int c2,int c3,ll cnt) -> void
    {
        if(cnt + msm[d] < ans) return;
        if(d == n + 1){
            ans = std::max(ans,cnt);
            return;
        }
        if(c1 + 1 <= maxa)
            dfs(dfs,d + 1,c1 + 1,c2,c3,cnt + a[d].x);
        if(c2 + 1 <= maxa)
            dfs(dfs,d + 1,c1,c2 + 1,c3,cnt + a[d].y);
        if(c3 + 1 <= maxa)
            dfs(dfs,d + 1,c1,c2,c3 + 1,cnt + a[d].z);
    };
    dfs(dfs,1,0,0,0,0);
    std::cout << ans << '\n';
}
void solve2(){
    std::sort(a + 1,a + n + 1,[&](const node &x,const node &y){
        return x.x > y.x;
    });
    for(int i = 1;i <= n / 2;i++)
        ans += a[i].x;
    std::cout << ans;
}
void solve3(){
    std::vector<node> A,B;
    for(int i = 1;i <= n;i++){
        if(a[i].x > a[i].y) A.push_back(a[i]);
        else B.push_back(a[i]);
    }
    if(A.size() > B.size()){
        std::sort(A.begin(),A.end(),[&](const node &lhs,const node &rhs){
            return lhs.x > rhs.x;
        });
        while(A.size() > B.size()) B.push_back(A.back()),A.pop_back();
    }
    else if(B.size() > A.size()){
        std::sort(B.begin(),B.end(),[&](const node &lhs,const node &rhs){
            return lhs.y > rhs.y;
        });
        while(B.size() > A.size()) A.push_back(B.back()),B.pop_back();
    }
    for(auto i : A)
        ans += i.x;
    for(auto i : B)
        ans += i.y;
    std::cout << ans << '\n';
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> T;
    while(T--){
        std::memset(msm,0,sizeof(msm));
        ans = 0;
        std::cin >> n;
        bool flagA = 1,flagB = 1,flagC = 1;
        for(int i = 1;i <= n;i++){
            std::cin >> a[i].x >> a[i].y >> a[i].z;
            if(a[i].y != 0 || a[i].z != 0) flagA = 0;
            if(a[i].z != 0) flagB = 0;
        }
            
        if(n <= 60)
            solve1();
        if(flagA)
            solve2();
        else if(flagB)
            solve3();
    }
    return 0;
}