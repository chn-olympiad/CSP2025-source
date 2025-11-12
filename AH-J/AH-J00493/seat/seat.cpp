#include<iostream>
#include<algorithm>
using namespace std;
bool f(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++) cin>>a[i];
    int R=a[1];
    sort(a,a+n*m,f);
    int p[n][m],x[n*m],y[n*m];
    int yt=0;
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>0;j--){
                y[yt]=j;
                yt++;
            }
        }else{
            for(int j=1;j<=n;j++){
                y[yt]=j;
                yt++;
            }
        }
    }
    int xt=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            x[xt]=i;
            xt++;
        }
    }
    int c;
    for(int i=0;i<=n*m;i++){
        if(a[i]==R){
            c=i+1;
            break;
        }
    }
    cout<<x[c]<<' '<<y[c];
}
