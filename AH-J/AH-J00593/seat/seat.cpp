#include<bits/stdc++.h>
using namespace std;
int a[105],m,n,ans;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    ans=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        int x,y;
        y=(i-1)/n+1;
        if(y%2!=0){
            x=i%n;
            if(x==0)    x=n;
        }else{
            x=n-i%n+1;
            if(x==n+1)  x=1;
        }
        if(a[i]==ans){
            cout<<y<<" "<<x;
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
}
