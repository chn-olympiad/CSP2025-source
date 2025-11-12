#include<bits/stdc++.h>
using namespace std;

int a[105],s,ra;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat1.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;++i){
        cin>>a[i];
    }
    s=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;++i){
        if(a[i]==s){
            ra=i;
            break;
        }
    }
    int tmp=ra%n;
    int c=(ra-tmp)/n+1,r;
    if(ra%n==0){
        c=ra/n;
        if(c%2==0)r=1;
        else r=n;
    }
    else{
        if(c%2==0){
            r=n*c-ra;
        }
        else{
           r=ra-n*c+n;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
