#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[110]={};
ll n,m,k=0,r=0;
ll s=0,x=0,y=0;
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=n*m;
    for(int i=1;i<=k;++i){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+1+k,cmp);
    for(int i=1;i<=k;++i){
        if(a[i]==r){
            s=i;
            break;
        }
    }
    x=(s-1)/n+1;
    if(x%2==1){

        y=s%n;
        if(y==0){
            y=n;
        }
    }else{
        y=n+1-(s%n);
    }
    cout<<x<<" "<<y;
    return 0;
}
