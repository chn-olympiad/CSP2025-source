#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int s=a[1],x,y;
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--){
        if(a[i]==s){
            int p=n*m-i+1;
            if(p%n==0){
                if(p/n%2==0){
                    x=1,y=p/n;
                }
                else{
                    x=n,y=p/n;
                }
            }
            else if(p%n!=0){
                if(p/n+1%2==0){
                    x=n-(p%n)+1,y=p/n+1;
                }
                else{
                    x=p%n,y=p/n+1;
                }
            }
        }
    }
    cout<<y<<" "<<x;
    return 0;
}

