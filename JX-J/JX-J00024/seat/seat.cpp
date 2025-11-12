#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int n,m,x,y,a[110],mm,r;
int main(){
    freopen("seat,in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        if(i%2!=0)
        for(int j=1;j<=m;j++){
            if(a[++mm]==r)return cout<<i<<" "<<j,0;
        }
        else         for(int j=m;j>=1;j--){
            if(a[++mm]==r)return cout<<i<<" "<<j,0;
        }
    }
    return 0;
}