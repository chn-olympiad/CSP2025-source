#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N],r,l,h;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    r=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            l=(i%n==0?i/n:i/n+1);
            h=(i%n==0?n:i%n);
            if(l%2==0) h=n-h+1;
            cout<<l<<" "<<h<<"\n";
            return 0;
        }
    }return 0;
}