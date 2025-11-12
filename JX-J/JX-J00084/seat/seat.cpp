#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],s,p;
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
    s=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==s){
            p=i;
        }
    }
    if(p%n==0){
        if((p/n)%2==0){
            cout<<p/n<<" "<<1;
        }else{
            cout<<p/n<<" "<<n;
        }
    }else{
        if((p/n+1)%2==0){
            cout<<p/n+1<<" "<<n-(p%n)+1;
        }else{
            cout<<p/n+1<<" "<<p%n;
        }
    }
    return 0;
}
