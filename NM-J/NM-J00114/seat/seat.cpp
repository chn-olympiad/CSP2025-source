#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
int r,ri;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int x=n*m;
    for(int i=1;i<=x;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+x+1,cmp);
    for(int i=1;i<=x;i++){
       if(a[i]==r){
            ri=i;
            break;
        }
    }
    int hang1=ri%n,hang;
    int lie=(ri-1)/n+1;
    if(lie%2==1){
        hang=hang1;
        if(hang==0) hang=n;
    }else{
        if(hang1==0) hang1=n;
        hang=n+1-hang1;
    }
    cout<<lie<<' '<<hang;
    return 0;
}
