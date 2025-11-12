#include<bits/stdc++.h>
using namespace std;
long long a,b,n,m,k,ma[100005],x[5][100005];
void dfs(long long sum,int w){
    if(w==n+1){
        k=max(k,sum);
        return ;
    }
    for(int i=1;i<=3;i++){
        if(ma[i]<=n/2-1){
            ma[i]++;
            dfs(sum+x[i][w],w+1);
            ma[i]--;
        }
    }
    return ;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        k=0;
        for(int i=1;i<=n;i++){
            cin>>x[1][i]>>x[2][i]>>x[3][i];
        }
        dfs(0,1);
        cout<<k<<endl;
    }
    return 0;
}
