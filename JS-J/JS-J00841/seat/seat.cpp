#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e2+10;
int n,m,t,x,y,a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            x=ceil(i*1.0/n);
            if(x&1){
                y=i%n;
                if(!y){
                    y=n;
                }
            }
            else{
                y=n-i%n+1;
                if(y==n+1){
                    y=1;
                }
            }
            cout<<x<<' '<<y;
        }
    }
    return 0;
}
//By Luogu Online Judge user 1400123
