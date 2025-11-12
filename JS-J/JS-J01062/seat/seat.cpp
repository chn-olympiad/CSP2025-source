#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[110];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1],x=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            x=i;
            break;
        }
    }
    int p=x/n,q=x%n;
    if(q==0){
        cout<<p<<" ";
        if(p%2==0){
            cout<<1;
        }else{
            cout<<n;
        }
    }else{
        cout<<p+1<<" ";
        if(p%2==0){
            cout<<q;
        }else{
            cout<<n+1-q;
        }
    }
    return 0;
}
