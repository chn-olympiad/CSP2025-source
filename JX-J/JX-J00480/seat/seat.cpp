#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,a[N*N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int t=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(t==a[i]){
            //cout<<i<<" ";
            int c=ceil((double)i/n);
            cout<<c<<" ";
            if(c%2==1){
                if(i%n==0)cout<<n-i%n;
                else cout<<i%n;
            }
            else{
                if(i%n)cout<<n+1-i%n;
                else cout<<1;
            }
            return 0;
        }
    }
    return 0;
}