#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],store,seat;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    store=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m*n;i++)
        if(a[i]==store){
            seat=i;
            break;
        }
    int lie;
    lie=ceil((float)seat/n);
    cout<<lie<<' ';
    int hang=seat-(lie-1)*n;
    if(lie%2==1) cout<<hang;
    else{
        if(hang==n) cout<<1;
        else if(hang==1) cout<<n;
        else cout<<n-hang+1;
    }
}
