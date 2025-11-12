#include <bits/stdc++.h>
using namespace std;
bool cmp(int q1,int q2){
    return q1>q2;
}
int a[300];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r_seat,seat;
    bool q=-1;
    int c=1,r=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r_seat=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){

        if(a[i]==r_seat){
            if(i%n==0){
                cout<<i/n;
            }
            else if(i%n!=0){
                cout<<i/n+1;
            }
            cout<<" ";
            if(i%(2*n)<=n){
                cout<<i%(n*2);
            }
            else{
                cout<<n-i%(2*n)+n+1;
            }
            return 0;
        }
    }
    return 0;
}
