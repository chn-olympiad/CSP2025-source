#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct node{
    int num,sum;
}a[100005];
bool cmp(node x,node y){
    return x.sum>y.sum;
}
int main(void){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].sum;
        a[i].num=i;
    }
    int l=a[1].sum,k,p;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].sum==l&&a[i].num==1){
            k=i;
            break;
        }
    }
    if(k%n==0)p=k/n;
    else p=k/n+1;
    int r;
    if(p%2==1){
        if(k%n==0)r=m;
        else r=k%n;
    }
    else{
        if(k%n==0)r=1;
        else r=m-k%n+1;
    }
    cout<<p<<" "<<r;
    return 0;
}
