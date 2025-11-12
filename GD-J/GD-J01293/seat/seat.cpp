#include<bits/stdc++.h>
using namespace std;
struct node{
    int pos,value;
}a[105];
int n,m,temp;
bool cmp(node x,node y){
    return x.value>y.value;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].value;
        a[i].pos=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*n;i++){
        if(a[i].pos==1) temp=i;
    }
    if(((temp-1)%(2*n)+1)<=n){
        cout<<temp/n+1<<" "<<(temp-1)%(2*n)+1;
        return 0;
    }
    cout<<temp/n+2<<" "<<2*n-(temp-1)%(2*n)<<" ";
    return 0;
}
