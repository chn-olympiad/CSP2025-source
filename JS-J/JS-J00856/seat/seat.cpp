#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000],fen,f;
long long cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>fen;
        if(i==1) f=fen;
        a[i]=fen;
    }
    sort(a+1,a+n*m+1,cmp);
    for(long long i=1;i<=n*m;i++){
        if(a[i]==f) {f=i;break;}
    }
    if(f<=n) {cout<<1<<" "<<f<<endl;return 0;}
    else {
        long long lie,hang;
        lie=f/n;
        if(f%n!=0) lie++;
        if(lie%2==1) {if(f%n==0) hang=n;else hang=f%n;}
        else {if(f%n==0) hang=1;else hang=n-f%n+1;}
        cout<<lie<<" "<<hang<<endl;
    }
    return 0;
}
