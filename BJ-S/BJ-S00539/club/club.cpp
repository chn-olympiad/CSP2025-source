#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
vector<vector<int> > a;
struct node{
    int an,bn,cn,sum;
};
int T,n;
int ans= 0;
vector<node> ans1;
int dx[] = {1,0,0};
int dy[] = {0,1,0};
int dz[] = {0,0,1};
void dfs1(int an,int bn,int cn,int sum,int i){
    if(an>n/2&&bn>n/2&&cn>n/2)return;
    if(i>=n/2){
        ans1.push_back({an,bn,cn,sum});
        return;
    }
    for(int k = 0;k<3;k++){
        dfs1(an+dx[k],bn+dy[k],cn+dz[k],sum+a[i][k],i+1);
    }
}
void dfs2(int an,int bn,int cn,int sum,int i){
    if(an>n/2&&bn>n/2&&cn>n/2)return;
    if(i>n){
        for(int k = 0;k<ans1.size();k++){
            //cout << ans1[k].an << ' ' << ans1[k].bn << ' ' << ans1[k].cn << '\n';
            if(an+ans1[k].an<=n/2&&bn+ans1[k].bn<=n/2&&cn+ans1[k].cn<=n/2){
                ans = max(ans,ans1[k].sum+sum);
            }
        }
        return;
    }
    for(int k = 0;k<3;k++){
        dfs2(an+dx[k],bn+dy[k],cn+dz[k],sum+a[i][k],i+1);
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n;
        a.assign(n+1,vector<int>(3,0));
        ans1.assign(n+1,{0,0,0,0});
        ans = 0;
        for(int i = 1;i<=n;i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        dfs1(0,0,0,0,1);
        dfs2(0,0,0,0,n/2);
        cout << ans << '\n';
    }
    return 0;
}
/*
g++ A.cpp -o A
./A

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

4
10 9 8
4 0 0
5 4 3
0 0 20
*/