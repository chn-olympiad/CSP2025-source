#include<bits/stdc++.h>
using namespace std;
int a[400],b,n,m,aa,r=1,c;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    aa=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==aa){
            while(i>n){
                i-=n;
                r++;
                b=1-b;
            }
            if(b) cout<<r<<' '<<n-i+1;
            else cout<<r<<' '<<i;
            return 0;
        }
    }
    return 0;
}
