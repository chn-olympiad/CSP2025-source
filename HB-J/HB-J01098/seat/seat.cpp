#include<bits/stdc++.h>
#define lxx 0
using namespace std;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,fro=1;
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            fro++;
        }
    }
    int l;
    if(fro%n==0){
        l=fro/n;
    }else{
        l=fro/n+1;
    }
    int r=fro-(l-1)*n;
    if(l%2==1){
        cout<<l<<" "<<r;
    }else{
        cout<<l<<" "<<n-r+1;
    }
    cout<<"\n";
    return lxx;
}