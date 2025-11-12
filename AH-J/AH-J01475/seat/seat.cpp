#include<bits/stdc++.h>
using namespace std;
const int N=15;
struct Node{int s,id;}a[N*N];
int n,m;
bool cmp(const Node &x,const Node &y){return x.s>y.s;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].s;
        a[i].id=i;
    }
    sort(a+1,a+1+n*m,cmp);
    int p=0;
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1) p=i;
    }
    int c=(p-1)/n+1,r;
    p-=n*(c-1);
    if(c%2==1) r=p;
    else r=n-p+1;
    cout<<c<<' '<<r<<endl;
    return 0;
}
