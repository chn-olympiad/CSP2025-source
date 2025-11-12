#include<bits/stdc++.h>
using namespace std;
int n,m;
struct c{
    int num;
    int f;
}a[10005];
bool cmp(c a,c b){
    return a.f>b.f;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].f;
        a[i].num=i;
    }
    sort(a+1,a+1+n*m,cmp);
    int k;
    for(int i=1;i<=n*m;i++){
        if(a[i].num==1){
            k=i;
            break;
        }
    }
    int r,c;
    c=k/n;
    if(c*n!=k){
        c++;
    }
    if(c%2==0){
        r=n-k%n+1;
    }else{
        r=k%n;
        if(k%n==0){
            r=n;
        }
    }
    //cout<<k<<endl;//////////////////////////////////////////
    cout<<c<<" "<<r;
    return 0;
}
