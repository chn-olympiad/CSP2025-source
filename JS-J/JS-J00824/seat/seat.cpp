#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[200];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1],s=0;
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            s=i;
        }
    }
    s=n*m-s+1;
    int c,r;
    c=s/n;
    if(s%n!=0) c++;
    if(c%2==1){
        r=s%n;
    }
    else{
        r=m-s%n+1;
    }
    if(r==0){
        r=n;
    }
    cout<<c<<" "<<r;
    return 0;
}
