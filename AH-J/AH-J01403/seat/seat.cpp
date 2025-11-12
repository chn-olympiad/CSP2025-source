#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200],p,pos;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for( int i=1;i<=n*m;i++ ){
        cin>>a[i];
    }
    p=a[1];
    sort(a+1,a+n*m+1,cmp);
    for( int i=1;i<=n*m;i++ ){
        if(p==a[i]){
            pos=i;
            break;
        }
    }
    int l=pos/n,h=pos-l*n;
    if(pos%n!=0) l++;
    if(l%2==1){
        if(h==0) h=n;
        else h=h;
    }else{
        if(h==0) h=1;
        else h=n-h+1;
    }
    cout<<l<<" "<<h;
    return 0;
}
