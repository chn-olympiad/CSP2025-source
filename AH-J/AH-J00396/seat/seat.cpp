#include<bits/stdc++.h>
using namespace std;
bool cmp(int &a,int&b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    int a[n*m+4]={};int g;cin>>g;a[1]=g;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);int p;
    for(int i=1;i<=n*m;i++){
        if(a[i]==g)p=i;
    }
    if(p%n==0){
        int lie=p/n;
        if(lie%2==0)cout<<lie<<" "<<1;
        if(lie%2==1)cout<<lie<<" "<<n;
        return 0;
    }
    int lie=p/n+1;
    int bb=lie%2;
    int hang;
    if(bb==1)hang=p%n;
    if(bb==0)hang=n-p%n+1;
    cout<<lie<<" "<<hang;





    return 0;
}
