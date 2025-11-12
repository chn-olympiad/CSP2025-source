#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int u[5005];
int ans,sum,res;
bool px(int a,int b){
    return a>b;
}
bool check(int x){
    long long s=0;
    for(int i=1;i<=x;i++){
        s+=u[i];
    }

    sort(u+1,u+x+1,px); //cout<<s<<' '<<u[1]<<'\n';
    if(s>u[1]*2){
        return 1;
    }else{
        return 0;
    }
}
void dg(int x,int y){
    if(x>0){
        for(int i=y;i<=n;i++){
            u[ans]=a[i];
            ans++;
            dg(x-1,y+1);
        }

    }
        //for(int i=1;i<=z;i++){
      //      cout<<u[i]<<' ';
    //    }
  //      cout<<'\n';

}

int main(){

    cin>>n;
    if(n<=2){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //for(int i=1;i<=n;i++){
      //  cout<<a[i]<<' ';
    //}
    for(int i=3;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            ans=1;
            memset(u,0,sizeof(u));
            dg(i,j);
            if(check(i)==1){
                sum=(sum+1)%998244353;
            }
        }

    }
    cout<<sum;

    return 0;
}
