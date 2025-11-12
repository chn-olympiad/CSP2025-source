#include<bits/stdc++.h>
using namespace std;
int a[105],nm,n,m,nr;
bool cmp(int a1,int a2){
    return a1>a2;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    nm=n*m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    nr=a[1];
    sort(a+1,a+nm+1,cmp);
    for(int i=1;i<=nm;i++){
        if(a[i]==nr){
            int l=i%(2*n);
            if(l<=n){
                cout<<(i+n-1)/n<<' '<<l;
                return 0;
            }
            l-=n;
            cout<<(i+n-1)/n<<' '<<n-l+1;
            return 0;
        }
    }
    return 0;
}
