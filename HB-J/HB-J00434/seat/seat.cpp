#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[105];
long long ans=0,id;
long long r,c;
long long pd;
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
    }
    ans=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(long long i=1;i<=n*m;i++){
        if(a[i]==ans){
            id=i;
            break;
        }
    }
    pd=ceil(id*1.00/n);
    if(pd%2==0){
        c=pd;
        r=n-(id-(pd-1)*n)+1;
    }
    else{
        c=pd;
        r=(id-(pd-1)*n);
    }
    cout<<c<<' '<<r<<endl;
    return 0;
}
