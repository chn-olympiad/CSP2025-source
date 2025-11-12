#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int w[200];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>w[i];
    }
    int t=w[1];
    sort(w+1,w+1+(n*m),cmp);
    for(int i=1;i<=n*m;i++){
        if(t==w[i]){
            t=i;
            break;
        }
    }
    // cout<<t<<endl;
    int k=0;
    if((t/n)*n==t){
            k=t/n;
            cout<<k;
    }
    else {k=t/n+1;cout<<k;}
    k-=1;
    //cout<<t<<endl<<k<<endl;
    cout<<' ';
    if(k%2==0)cout<<t-(n*k);
    else cout<<n-t+(n*k)+1;
    cout<<endl;
    return 0;
}
