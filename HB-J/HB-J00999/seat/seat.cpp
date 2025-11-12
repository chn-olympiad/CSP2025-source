#include<bits/stdc++.h>
using namespace std;
struct node{
    int s;
    bool r;
};
bool cmp(node a,node b){
    return a.s>b.s;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    node a[n*m]={};
    int b[n][m]={};
    for(int i=0;i<n*m;i++)cin>>a[i].s;
    a[0].r=1;
    sort(a,a+n*m,cmp);
    int k=1,d=1;
    for(int i=0;i<n*m;i++){
        //cout<<k<<' '<<d<<'\n';
        if(a[i].r)cout<<d<<' '<<k<<'\n';
        b[k-1][d-1]=a[i].s;
        if(k==n&&d%2==1)d++;
        else if(k==1&&d%2==0)d++;
        else if(d%2==1)k++;
        else k--;
    }
    return 0;
}
