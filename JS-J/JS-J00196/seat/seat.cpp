#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[105];
    cin>>a[1];
    int _=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==_){
            _=i;
            break;
        }
    }
    int c=(_-1)/n+1;
    int r;
    if(c%2==0){
        r=n-(_-1)%n;
    }
    else{
        r=(_-1)%n+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
