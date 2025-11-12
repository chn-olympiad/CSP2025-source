#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],nm,r,ri,k,b;
bool mycmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    nm=n*m;
    for(int i=1;i<=nm;i++){
        cin>>a[i];
        if(i==1){
            r=a[i];
        }
    }
    sort(a+1,a+nm+1,mycmp);
    for(int i=1;i<=nm;i++){
        if(a[i]==r){
            ri=i;
            break;
        }
    }
    k=ri/n;
    b=ri%n;
    if(k%2==1){
        if(b==0){
            cout<<k<<" "<<n;
        }
        else{
            cout<<k+1<<" "<<n-b+1;
        }
    }
    else{
        if(b==0){
            cout<<k<<" "<<1;
        }
        else{
            cout<<k+1<<" "<<b;
        }
    }
    return 0;
}
