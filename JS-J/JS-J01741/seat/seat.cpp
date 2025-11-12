#include<bits/stdc++.h>
using namespace std;
int a[114];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    int l=n*m;
    for(int i=1;i<=l;i++)cin>>a[i];
    int r=a[1];
    sort(a+1,a+l+1);
    for(int i=l,_n=1,_m=1;i>0;i--){
        if(a[i]==r){
            cout<<_m<<' '<<_n;
            break;
        }
        if(_m%2!=0){
            if(_n!=n)_n++;
            else _m++;
        }else {
            if(_n!=1)_n--;
            else _m++;
        }
    }

    return 0;
}
