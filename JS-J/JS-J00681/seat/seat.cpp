#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100010],cnt,w;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;k=n*m;cnt=1;cin>>w;
    for(int i=2;i<=k;i++){
        cin>>a[i];
        if(a[i]>w)cnt++;
    }
    int x,y,t;
    if(cnt%n==0)x=(cnt/n);
    else x=(cnt/n)+1;
    t=cnt-(x-1)*n;
    if(x%2==1)y=t;
    else y=n-t+1;

    cout<<x<<' '<<y<<endl;
    return 0;
}
