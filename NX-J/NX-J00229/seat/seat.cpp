#include <bits/stdc++.h>
using namespace std;
int a[1000];
bool cmp(int a,int b){
     return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,y;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];

    }
    int q=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==q){q=i;}
    }
    x=ceil(q*1.0/n);
    if(x%2!=0){
        y=q-n*(x-1);
    }
    else{
        y=q-n*(x-1);
        y=n-y+1;
    }
    cout<<x<<" "<<y;
    return 0;
}
