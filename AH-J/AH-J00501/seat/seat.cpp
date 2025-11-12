#include<iostream>
#include<cstdio>
#include<algorithm>
//define bits/stdc++.h
using namespace std;
int n,m,a[10005];
int r,id;
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
    r=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
//            cout<<a[i]<<" ";
        if(a[i]==r){
            id=i;
            break;
        }
    }
//    cout <<"\n";
    cout<<(id+n-1)/n<<" ";
    int mm=(id+n-1)/n,nn=id-id/n*n;
    if(mm%2){
        if(nn==0) cout<<n;
        else cout<<nn;
    }
    else{
        cout<<n+1-nn;
    }
    return 0;
}
