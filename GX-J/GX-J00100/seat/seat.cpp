#include<bits/stdc++.h>
using namespace std;

int n,m;

void seat_where(int s){
    int c=0;
    if(s%n)
        c=floor(s/n)+1;
    else
        c=s/n;
    int r=0;
    if(c%2)
        r=s-(c-1)*n;
    else
        r=n-(s-(c-1)*n)+1;

    cout<<c<<' '<<r;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    int a;
    cin>>a;
    int co=1;
    for(int i=2;i<=n*m;++i){
        int os;
        cin>>os;
        if(os>a)
            ++co;
    }
    seat_where(co);

    return 0;
}
