#include<bits/stdc++.h>
using namespace std;
long long n,m,s[105],a,b,c,r;
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
    }
    a=s[1];
    sort(s+1,s+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(s[i]==a){
            b=i;
            break;
        }
    }
    if(b%n==0){
        c=b/n;
    }else{
        c=b/n+1;
    }
    if(c%2==1){
        r=b%n;
        if(r==0){
            r=n;
        }
    }else{
        r=n-b%n+1;
        if(r==n+1){
            r=1;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
