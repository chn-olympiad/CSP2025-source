#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b=0;
}x[105];
bool cmp(node a,node b){
    return a.a>b.a;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>x[i].a;
    int w=x[1].a;
    sort(x+1,x+n*m+1,cmp);
    int t=0,a[15][15];
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
                t++;
                a[j][i]=x[t].a;
            }
        }
        else{
            for(int j=1;j<=n;j++){
                t++;
                a[j][i]=x[t].a;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(w==a[i][j]){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
