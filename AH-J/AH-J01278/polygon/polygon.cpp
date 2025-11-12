#include<bits/stdc++.h>
using namespace std;
int N,A[5050],Vis[5050],B[5050],Cnt=0;
int dfs(int X,int Y){
    if(Y>=3){
        Cnt++;
    }
    for(int i=X;i<N;i++){
        if(Vis[i]==0){
            Vis[i]==1;
            dfs(X,Y+1);
            B[Y]=X;
        }
    }
    return Cnt;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[5050];
    }
    int X=dfs(0,0);
    cout<<X;
    return 0;
}
