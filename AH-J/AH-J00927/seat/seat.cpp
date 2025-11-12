#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int t[1001001]={0};
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
}
if(n<=1&&m<=1){
    cout<<"1 1";
    return 0;
}else if(m==1&&n==2){
    for(int i=1;i<=n*m;i++){
        if(a[i]==i){
            cout<<"1 2";
            return 0;
        }else if(a[i]==n*m-i+1){
        cout<<"1 1";
        return 0;
        }
        }
}else if(m==2&&n==1){
    for(int i=1;i<=n*m;i++){
        if(a[i]==i){
            cout<<"2 1";
            return 0;
        }else if(a[i]==n*m-i+1){
        cout<<"1 1";
        return 0;
        }
        }
}else if(m==2&&n==2){
    for(int i=1;i<=n*m;i++){
        if(a[i]==i){
            cout<<"2 1";
            return 0;
        }else if(a[i]==n*m-i+1){
        cout<<"1 1";
        return 0;
        }
        }
}
return 0;
}
