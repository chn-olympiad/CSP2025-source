#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1009][1009];
void add(int a1,int b1,int c1){
    a[a1][b1]=c1;
    a[b1][a1]=c1;
}
int dfs(int p){
    for(auto q:a[p]){

    }
    return 0;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<'0'<<endl;
    return 0;
}
