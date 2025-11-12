#include<bits/stdc++.h>
using namespace std;
int a[100010] , b[100010] , c[100010];
int d[100010];
int main(){
    freopen("rode.in","r",stdin);
    freopen("rode.out","w",stdout);
    int n , m , k;
    cin >> n >> m >> k;
    for(int i = 1 ; i <= m ; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    int cnt = 0;
    vector<priority_queue<int>> q;
    for(int i = 1 ; i <= k ; i++){
        cin >> d[i];
        for(int j = 1 ; j <= n ; j++){
            int xx;
            cin >> xx ;
            q[i].push(xx);
        }
    }
    int minn = INT_MAX;
    for(int i = 1 ; i <= k ; i++){
        minn = min(minn,d[i]);
    }
    int z ;
    for(int i = 1 ; i <= k ; i++){
        if(d[i] == minn){
            z = i;
            break;
        }
    }
    sort(c+1,c+1+m);
    for(int i = m ; i >= m - 2 ; i--)cnt += c[i];
    cnt += q[z].top();
    cout << cnt;
    return 0;
}
