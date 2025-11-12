#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1)s=a[i];
    }
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(a[i]==s){
            if((n*m-i+1)%n!=0){
                cout<<(n*m-i+1)/n+1<<' ';
                int x=(n*m-i+1)/n+1;
                if(x%2!=0){
                    if((n*m-i+1)%m==0)cout<<m;
                    else cout<<(n*m-i+1)-x*m+m;
                }
                else{
                    if((n*m-i+1)%m==0)cout<<1;
                    else cout<<m*x-(n*m-i+1)+1;
                }
            }
            else {
                cout<<(n*m-i+1)/n<<' ';
                int x=(n*m-i+1)/n;
                if(x%2!=0){
                    if((n*m-i+1)%m==0)cout<<m;
                    else cout<<(n*m-i+1)-x*m+m;
                }
                else{
                    if((n*m-i+1)%m==0)cout<<1;
                    else cout<<m*x-(n*m-i+1)+1;
                }
            }
            break;
        }
    }
    return 0;
}
