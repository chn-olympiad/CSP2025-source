#include<bits/stdc++.h>
using namespace std;

int r,n,m,a[105];

signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    r=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m/2;i++){
        swap(a[i],a[1+n*m-i]);
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            if((i%(2*n))>n){
                if(i%(2*n)==n+1){
                    cout<<(i/n+1)<<" ";
                    cout<<n;
                }
                else{
                    cout<<(i/n+1)<<" ";
                    cout<<1+2*n-i%(2*n);
                }
            }
            else{
                if(i%(2*n)==0){
                    cout<<(i/n)<<" ";
                    cout<<1;
                }
                else if(i%n==0){
                    cout<<(i/n)<<" ";
                    cout<<n;
                }
                else{
                    cout<<(i/n+1)<<" ";
                    cout<<(i%(2*n));
                }
            }
            return 0;
        }
    }
    /*
    for(int i=n*m;i>0;i--){
        cout<<"a["<<i<<"]:"<<a[i]<<endl;
        if(a[i]==r){
            int k=1+n*m-i;
            if(k%(2*n)>n){
                cout<<k%n+1<<" "<<1+n-k%(2%n);
            }
            else{
                cout<<k%n+1<<" "<<k%(2*n);
            }
            return 0;
        }
    }
    */
}
