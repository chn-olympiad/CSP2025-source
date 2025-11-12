#include<bits/stdc++.h>
using namespace std;
int a[130];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
            cin>>a[i];
    }
    int t=a[0];
    int p;
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(a[i]==t){
            p=i+1;
        }
    }
    int c;
    int tem=p%n;
    int r;
    if(tem==0){
        c=p/n;
        if(c%2==1){
            r=n;
        }
        else{
            r=1;
        }
    }
    else{
        c=p/n+1;
        if(c%2==1){
            r=tem;
        }
        else{
            r=n-tem+1;
        }
    }

    cout<<c<<' '<<r;
    return 0;
}
