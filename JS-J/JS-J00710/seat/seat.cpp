#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],t,pos;

bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            pos=i;
            break;
        }
    }
    int p=pos/n,q=pos%n;
    p++;
    if(q==0){
        p--;
        q=n;
    }
    if(p%2==0){
        q=m+1-q;
    }
    cout<<p<<" "<<q<<"\n";
    return 0;
}   