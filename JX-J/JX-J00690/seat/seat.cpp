#include <bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b){
        return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    cin>>n>>m;
    cin>>r;
    a[1]=r;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    int x,y;
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            cout<<ceil(i*1.0/n*1.0)<<' ';
            if((i/n)%2==0||i==n){
                if(i%(i/n*n)==0){
                    cout<<n;
                    return 0;
                }
                else{
                    cout<<i%(i/n*n);
                    return 0;
                }

            }
            else{
                cout<<n+1-(i%(i/n*n));
            }
            return 0;
        }
    }
    return 0;
}
