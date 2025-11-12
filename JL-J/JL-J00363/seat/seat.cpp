#include <bits/stdc++.h>
using namespace std;
//int a[15][15];
int s[105];
bool cmp(int a,int b){
    return a>b;
}
int f (int x,int y,int z){
    if(y%2==0){
        return x-2*z;
    }else{
        return (y+1)*z-x+1;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt,w,ming;
    cin>>n>>m;
    cnt=n*m;
    for(int i=1;i<=cnt;i++){
        cin>>s[i];
    }
    w=s[1];
    sort(s+1,s+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        if(s[i]==w){
            ming=i;
            break;
        }
    }
    for(int i=1;i<=cnt;i++){
        if(ming>=1&&ming<=n){
            cout<<"1 "<<ming;
            break;
        }
        if(ming>=i*n &&ming<=(i+1)*n){
            cout<<i<<" "<<f(ming,i,n);
            break;
        }
    }




    //if(ming>n&&ming<=2*n){
        //cout<<"2 "<<2*n-ming+1;
    //}
    //if(ming>2*n&&ming<=3*n){
      //  cout<<"3 "<<ming-2*n;
    //}
    //for(int i=1;i<=n;i++){
        //for(int j=1;j<=m;j++){
          //  cin>>a[i][j];
        //}
    //}

    return 0;
}

