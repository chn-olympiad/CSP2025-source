#include <bits/stdc++.h>
using namespace std;
int ma_n,ma_m,ma_sort[105],ans,c,r;
bool cmp(const int x,const int y){
    return x>y?true:false;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>ma_n>>ma_m;
    for(int i=1;i<=ma_n*ma_m;i++)
        cin>>ma_sort[i];
    int R=ma_sort[1];
    sort(ma_sort+1,ma_sort+ma_n*ma_m+1,cmp);
    for(int i=1;i<=ma_n*ma_m;i++)
        if(ma_sort[i]==R) ans=i;
    c=(ans+ma_n-1)/ma_n;
    if(c%2==1){
        r=ans%ma_n;
        if(r==0) r=ma_n;
    }
    else{
        r=ma_n-ans%ma_n+1;
        if(r==ma_n+1) r=1;
    }
    cout<<c<<' '<<r;
    return 0;
}
