#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],now;
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    now=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==now){
            now=i;
            break;
        }
    }
    int now_n,now_m=ceil(1.0*now/n);
    if(now_m%2==1){
        now_n=now-(now_m-1)*n;
    }
    else now_n=n-(now-(now_m-1)*n)+1;
    cout<<now_m<<" "<<now_n;
    return 0;
}
