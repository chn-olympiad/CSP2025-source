#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int d;
    bool n;
}a[1000006];
bool cmp(node x,node y){
    return x.d>y.d;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].d;
    }
    a[1].n=1;
    sort(a+1,a+n*m+1,cmp);//warning!
    int c,r;
    for(int i=1;i<=n*m;i++){
        if(a[i].n){
            c=i/n;
            r=i%n;
            if(r!=0) c++;
            else r=n;
            if(c%2==0) r=n-r+1;

        }
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
