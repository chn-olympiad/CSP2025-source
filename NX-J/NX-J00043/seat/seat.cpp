#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],l=1,r=1,q;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    q=a[1];
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--){
        if(a[i]==q){
            cout<<l<<' '<<r;
            return 0;
        }
        if(l%2==1){
            r++;
            if(r%n==1){
                r=n;
                l++;
            }
        }
        else{
            r--;
            if(r==0){
                r=1;
                l++;
            }
        }
    }
    return 0;
}
