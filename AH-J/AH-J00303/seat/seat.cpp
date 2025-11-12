#include<bits/stdc++.h>
using namespace std;
int n,m,u=1,v=1,f=1;
int a[105],ans[15][15];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        ans[u][v]=a[i];
        if(a[i]==t){
            cout<<v<<" "<<u;
            break;
        }
        u+=f;
        if(u>n){
            u--;
            v++;
            f=-f;
        }
        if(u<1){
            u++;
            v++;
            f=-f;
        }
    }
    return 0;
}
