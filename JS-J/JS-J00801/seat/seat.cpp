#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int a[110];
int cm(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }s=a[1];
    sort(a+1,a+n*m+1,cm);
    int i=0;
    for(i=1;i<=n*m;i++){
        if(a[i]==s){
            break;
        }
    }
    if(i%n==0){
        s=i/n;
        cout<<i/n<<" ";
    }else{
        s=i/n+1;
        cout<<i/n+1<<" ";
    }
    if(s%2==1){
        if(i%n==0){
            cout<<n;
        }else{
            cout<<i%n;
        }
    }else{
        if(i%n==0){
            cout<<1;
        }else{
            cout<<n-i%n+1;
        }
    }
    return 0;
}
