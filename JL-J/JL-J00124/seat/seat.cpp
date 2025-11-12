#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],ans,f;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++){
        cin>>a[i];
        if(a[i]>a[1]){
            ans++;
        }
    }
    int l=1,r=1;
    for(int i=1; i<=ans; i++){
        if(f==0){
            l++;
        }else{
            l--;
        }
        if(l>n){
            l--;
            f=1;
            r++;
        }
        else if(l<1){
            l++;
            f=0;
            r++;
        }
    }
    cout<<r<<' '<<l;
    return 0;
}
