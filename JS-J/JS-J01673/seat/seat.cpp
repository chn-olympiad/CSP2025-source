#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],r,pos,ansx,ansy;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1)r=a[i];
    }
    sort(a+1,a+1+n*m);
    pos=lower_bound(a+1,a+1+n*m,r)-a;
    pos=n*m-pos+1;
    ansy=pos/n;
    if(pos%n!=0)ansy++;
    ansx=pos%n;
    if(pos%n==0)ansx=n;
    if(ansy%2==0){
        ansx=n-ansx+1;
    }
    cout<<ansy<<' '<<ansx;
    return 0;
}
