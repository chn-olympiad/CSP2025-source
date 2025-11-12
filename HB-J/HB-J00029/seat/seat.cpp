#include<bits/stdc++.h>
using namespace std;

int n,m,p[105],x,lie;

bool mcp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>p[i];
    }
    x=p[1];
    sort(p+1,p+m*n+1,mcp);
//    for(int i=1;i<=n*m;i++)
//        cout<<p[i]<<" ";
    for(int i=1;i<=m*n;i++){
        if(i%n==1)
            lie++;
        if(p[i]==x){
            cout<<lie<<" ";
            if(lie%2==1){
                cout<<i-n*(lie-1);
            }
            else{
                cout<<n-(i-n*(lie-1))+1;
            }
        }
    }

    return 0;
}
