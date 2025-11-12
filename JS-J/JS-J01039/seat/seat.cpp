#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[110],r,cur,hang,lie;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=n*m;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++){
        if(a[i]==r){
            cur=i;
        }
    }
    if(cur%n==0){
        lie=cur/n;
    }
    else{
        lie=cur/n+1;
    }
    if(cur%n==0){
        hang=n;
    }
    else{
        hang=cur%n;
    }
    if(lie%2==0){
        hang=n-hang+1;
    }
    cout<<lie<<' '<<hang;
    return 0;
}
