#include<bits/stdc++.h>
using namespace std;
long long a[11][11];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x[121];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>x[i];
    }
    int v=x[1],d=1;
    sort(x+1,x+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(i%2==0){
            for(int j=m;j>=1;j--){
                a[i][j]=x[d];
                d++;
                if(v==x[d]){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }else{
            for(int j=1;j<=m;j++){
                a[i][j]=x[d];
                d++;
                if(v==x[d]){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
