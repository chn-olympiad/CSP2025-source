#include <bits/stdc++.h>
using namespace std;
int n,m,r,s;
int a[104];
bool cmp(int x,int y){
    if(x>=y)return true;
    return false;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>r;
    a[1]=r;
    for(int i=2;i<=n*m;i++)scanf("%d",&a[i]);
    sort(a+1,a+n*m+1,cmp);
   // for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
    for(int i=1;i<=n*m;i++){
        if(r==a[i]){
            s=i;
            break;
        }
    }
    int l=(s+n-1)/n,h=s%n;
    if(l%2==0){
        cout<<l<<" "<<n-h+1;
    }else{
        if(h==0)cout<<l<<" "<<n;
        else cout<<l<<" "<<h;
    }
    return 0;
}
