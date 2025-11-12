#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],c,ansl,ansh,w;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
        if(i==1) c=a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==c) {
            w=i;
            break;
        }
    }
    if(w<=n){
        ansl=1;
        ansh=w;
    }
    else{
    for(int i=2;i<=m;i++){
        if(w<=(n*m)&&w>(n*(m-1))){
            ansl=m;
            if(m%2==0){
                ansh=((m*n)-w)+1;
            }
            else{
                ansh=w%(n*(m-1));
            }
        }
    }
    }
    cout<<ansl<<" "<<ansh;
    return 0;
}
