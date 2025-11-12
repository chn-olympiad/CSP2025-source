#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N][4],t,ti[4];
long long maxn;
void dfs(int la,long long tot){
    if(la==n+1){
        maxn=max(maxn,tot);
        return;
    }
    for(int i=1;i<=3;i++){
        if(ti[i]>=(n/2)) continue;
        ti[i]++;
        dfs(la+1,tot+a[la][i]);
        ti[i]--;
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
        maxn=0;
        dfs(1,0);
        cout<<maxn<<endl;
    }
    return 0;
}
//g++ -o test test.cpp -O2 -std=c++14 -static
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
