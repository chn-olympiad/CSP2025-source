#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,c,r;
    int a[10010];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[1]==100){
            c=1;r=1;
        }
        int s=100-a[1];
        if(1+s<=n){
            c=1;r=1+s;
        }
        else{
            if(m%2==0){
                c=1+s/n;r=n-s/n;
            }
            else if(m%2!=0){
                c=1+s/n;r=1+s/n;
            }

        }

    }
    cout<<c<<' '<<r;

    return 0;
}
