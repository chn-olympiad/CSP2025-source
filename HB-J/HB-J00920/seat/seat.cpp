#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c,r;
bool cmp(int x,int y){
    if(x!=y){
        return x>y;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int xiao=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==xiao){
            c=ceil(1.0*i/n);
            if(i%(n*2)<=n){
                if(i%n==0){
                    r=n;
                }
                else r=i%n;
            }
            else{
                if(i%n==0){
                    r=1;
                }
                else r=n-(i%n)+1;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
