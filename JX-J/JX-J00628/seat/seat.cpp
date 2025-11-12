#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
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
    int xm=a[1],w=1;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==xm){
            w=i;
            break;
        }
    }
    for(int i=1;i<=m;i++){
        if(w<=i*n&&w>(i-1)*n){
            if(i%2==0){
                cout<<i<<" "<<i*n-w+1;
            }else{
                cout<<i<<" "<<w-(i-1)*n;
            }
            return 0;
        }
    }
    return 0;
}
