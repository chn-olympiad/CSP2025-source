#include <bits/stdc++.h>
using namespace std;
int Find(int b[102],int x){
    for(int i=0;;i++){
        if(b[i]==x){
            int t=i;
            return t;
        }
    }
}
int n,m;
int l[12][12],a[102];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int h=a[0];
    sort(a,a+n*m);
    int fhz=Find(a,h);
    if(fhz<=n){
        cout<<1<<" "<<fhz;
    }
    else if(fhz>n){
        if(m=1){
            cout<<1<<" "<<1;
        }
        else if(m=2){
            cout<<n+1-fhz%n<<" "<<fhz%(2*m-4);
        }
        else{
            cout<<n+1-fhz%n<<" "<<m-fhz%(2*m-4)-1;
        }
    }
    return 0;
}
