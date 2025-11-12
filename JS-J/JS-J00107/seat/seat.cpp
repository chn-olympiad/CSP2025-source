#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int n,m;
    cin>>n>>m;
    int a[110];
    for(int i=0;i<(n*m);i++){
        cin>>a[i];
    }
    int k=a[0];
    sort(a,a+(m*n));
    int it=find(a,a+n*m,k)-a;
    sort(a,a+(m*n),greater<int>());
    it=n*m-it;
    int l,h;
    l=it/(2*n)*2;
    it%=(2*n);
    if(it==0){
        h=1;
    }
    else if(it<=n){
        h=it;l++;
    }
    else{
        h=2*n-it+1;l+=2;
    }
    cout<<l<<' '<<h;
    return 0;
}
