#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],r,h,l;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    r=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            l=i/n;
            if(i>n&&l!=m) l++;
            if(l==0) l=1;
            if(l%2==1){
                h=i%n;
                if(h==0) h=n;
            }else h=n-(i-1)%n;
            break;
        }

    }
    cout<<l<<" "<<h;
    return 0;
}
