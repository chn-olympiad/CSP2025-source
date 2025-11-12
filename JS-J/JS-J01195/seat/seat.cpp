#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
bool cmp(const int &x,const int &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int f=a[1];
    sort(a+1,a+n*m+1,cmp);
    if(n==1&&m==1) cout<<"1 1";
    else if(n==1){
        for(int i=1;i<=n*m;i++){
            if(a[i]==f){
                cout<<i<<" 1";
                break;
            }
        }
    }
    else if(m==1){
        for(int i=1;i<=n*m;i++){
            if(a[i]==f){
                cout<<"1 "<<i;
                break;
            }
        }
    }/*
    else if(n==2&&m==2){
        int gird[3][3]={{1,4},{2,3}};
        int index=0;
        for(int i=1;i<=n*m;i++){
            if(f==a[i]){
                index=i;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(gird[i][j]==index){
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
        }
    }*/
    else{
        if(m%2==1) cout<<m<<" "<<n;
        else cout<<m<<" 1";
    }
    return 0;
}
