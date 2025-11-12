#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std ;
const int N = 2e2+10;
int n ;
bool flag[N] = {} ;
int a[N][3] = {} ;
int res = 0 ;
void dfs(int p,int A,int b,int ans){
    cout << p << " " << A << " " << b << " " << ans << "\n" ;
    int P = p-1;
    int c = P-A-b;
    if(A>n/2||b>n/2||c>n/2) return ;
    if(p==n+1){
        res = max(res,ans);
        return ;
    }
    for(int i = 1 ; i <= n ; i ++){
        if(flag[i]) continue;
        flag[i] = 1 ;
        dfs(p+1,A+1,b+0,ans+a[p][0]);
        dfs(p+1,A+0,b+1,ans+a[p][1]);
        dfs(p+1,A+0,b+0,ans+a[p][2]);
        flag[i] = 0 ;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        cin >>n ;
        res = 0 ;
        memset(flag,0,sizeof flag);
        bool nine = 1 ;
        for(int i = 1 ; i<= n ; i ++){
            cin >> a[i][0] >> a[i][1] >> a[i][2] ;
            if(a[i][0]>0||a[i][1]>0) nine = 0 ;
        }
        if(nine){
            vector<int> v(n);
            for(int i = 1 ; i <= n ; i ++)
                v[i-1] = a[i][0];
            sort(v.begin(),v.end());
            for(int i = n-1 ; i >= n/2-1 ; i --)
                res+=v[i];
        }
        else
            dfs(1,0,0,0);
        cout << res << "\n";
    }
    return 0;
}
