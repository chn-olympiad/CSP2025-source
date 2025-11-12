#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,an,am;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            r=i;
            break;
        }
    }
    am=(r%n==0?r/n:r/n+1);
    an=(am%2==0?n-r%n+1:(r%n==0?n:r%n));
    cout<<am<<' '<<an;
}