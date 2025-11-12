#include<bits/stdc++.h>
using namespace std;
long long n,m;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    long long a[n*m+5]={0},r,rr,ansm=0,ansn=0;
    for(long long i=1;i<=n*m;i++) cin>>a[i];
    r=a[1];
    sort(a+1,a+n*m+1,cmp);//weizhi
    for(long long i=1;i<=n*m+1;i++){
        if(a[i]==r) rr=i;
    }
    if(rr%n==0){
        if((rr/n)%2==1) cout<<rr/n<<" "<<n;
        if((rr/n)%2==0) cout<<rr/n<<" "<<1;
        return 0;
    }
    else{
        if((rr/n+1)%2==1) cout<<rr/n+1<<" "<<rr%n;
        if((rr/n+1)%2==0) cout<<rr/n+1<<" "<<n-rr%n+1;
        return 0;
    }
    return 0;
}//lie hang
