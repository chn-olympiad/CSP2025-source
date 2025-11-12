#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+1+n*m,cmp);
    int seat;
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            seat=i;
        }
    }
    int lie,hang;
    for(int i=1;i<=m;i++){
        if(seat<=i*n){
            lie=i;
            break;
        }
    }
    if(lie%2){
        hang=seat-(lie-1)*n;
    }
    else{
        hang=n-(seat-(lie-1)*n)+1;
    }
    cout<<lie<<' '<<hang;
    return 0;
}
