#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>b[1];
    int x=b[1];
    for(int i=2;i<=n*m;i++){
        cin>>b[i];
    }
    sort(b+1,b+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(b[i]==x){
            i=n*m-i+1;
            cout<<(i-1)/n+1<<" ";
            if(((i-1)/n+1)%2==1){
                if(i%n==0)cout<<n;
                else cout<<i%n;
            }
            else{
                if(i%n==0)cout<<1;
                else cout<<n-i%n+1;
            }
            break;
        }
    }
    return 0;
}
