#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[110],y,k;
bool tsa(){
    for(int l=1;l<=m*n;l++){
        if(a[l]!=l) return false;
    }
    return true;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++) cin>>a[i];
    if(tsa()) cout<<m<<" "<<n;
    for(int i=1;i<=m*n;i++){
        int bg=-1,f=-1;
        for(int j=1;j<=n*m;j++){
            if(a[j]>bg){
                bg=a[j];
                f=j;
            }
        }
        k+=1;
        b[k]=bg;
        a[f]=0;
        if(f==1) y=k;
    }
    for(int i=0;i<m;i++){
        if(y>=n*i+1 && y<=n*(i+1)){
            if((i+1)%2==0){
                y-=n*i;
                y=n-y;
                cout<<i+1<<" "<<y;
                return 0;
        }else{
                y-=n*i;
                cout<<i+1<<" "<<y;
                return 0;
            }
        }
    }
}
