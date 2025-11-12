//1.2
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,sum,ans,m[5][100005],v[5],num[100005];

void Dfs(ll s){
    if(s == n+1){
        sum = 0;
        for(ll i = 1;i <= n;i++){
            sum += num[i];
        }
        if(sum > ans){
            ans = sum;
        }
    }
    for(ll i = 1;i < 4;i++){
        if(v[i] != 0){
            v[i]--;
            num[s] = m[i][s];
            Dfs(s+1);
            v[i]++;
        }
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        //chushihua
        cin>>n;
        v[1] = v[2] = v[3] = n/2;
        ans = 0;
        for(ll i = 1;i <= n;i++){
            cin>>m[1][i]>>m[2][i]>>m[3][i];
        }
        Dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
