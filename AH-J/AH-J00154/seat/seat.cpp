#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int h,c,r,s;
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
    s=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==s){
            h=i;
            break;
        }
    }
    c=1;
    while(h>n){
        c++;
        h=h-n;
    }
    if(c%2==0){
        r=n+1-h;
    }else{
        r=h;
    }
    cout<<c<<" "<<r;
    return 0;
}
