#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,man[105],a,dp[15][15];
    cin>>n>>m;
    int le=n*m;
    for(int i=1;i<=le;i++){
        cin>>man[i];
    }
    a=man[1];
    for(int i=1;i<=le;i++){
        for(int j=1;j<=le-1;j++){
            if(man[j]<man[j+1]) swap(man[j],man[j+1]);
        }
    }
    int r,x,y;
    for(int i=1;i<=le;i++){
        if(man[i]==a) r=i;
    }
    x=(r+1)/n;
    y=r%n;
    if(x%2==0){
        y=n+1-y;
    }
    if(y==0){
        y=n;
    }
    cout<<x<<' '<<y;
}
