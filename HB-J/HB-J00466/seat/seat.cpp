#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int a[111];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r=a[1];
    int p;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            p=i;
            break;
        }
    }
    if(n==1){
        cout<<p<<" "<<1;
        return 0;
    }else if(m==1){
        cout<<1<<" "<<p;
        return 0;
    }else{
        int x=p/n;
        if(p%n!=0) x++;
        int y0=p%n,y;
        if(x%2==0) y=n-y0+1;
        else{
            if(y0==0){
                y=n;
            }else{
                y=y0;
            }
        }
        cout<<x<<" "<<y;
    }
    return 0;
}
