#include<bits/stdc++.h>
using namespace std;
int n,m,ans_n,ans_m,k,r,a[114];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=n*m;
    cin>>a[1];
    r=a[1];
    for(int i=2;i<=k;i++){
        cin>>a[i];

    }
    int pos;
    sort(a+1,a+1+k,cmp);
    for(int i=1;i<=k;i++){
        if(a[i]==r){
            pos=i;
            break;
        }
    }
    ans_m=(pos+n-1)/n;
    ans_n=pos-(ans_m-1)*n;
    if(!(ans_m%2))ans_n=n+1-ans_n;
    cout<<ans_m<<' '<<ans_n;
    return 0;
}
