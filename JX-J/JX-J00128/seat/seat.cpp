#include<bits/stdc++.h>
using namespace std;
int n,m,f,c,r;
int s[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>s[i];
    f=s[1];
    sort(s+1,s+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(s[i]==f){
            f=i;
            break;
        }
    }
    if(f%n==0) c=f/n;
    else c=f/n+1;

    if(c%2!=0){
        if(f%n==0) r=n;
        else r=f%n;
    }
    else{
        if(f%n==0) r=1;
        else r=n+1-f%n;
    }
    cout<<c<<' '<<r;
    return 0;
}
