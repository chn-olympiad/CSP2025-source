#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
int x,sz,num,ans,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    sz=n*m;
    for(int i=1;i<=sz;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+1+sz);
    for(int i=sz;i>=1;i--){
        if(a[i]==x){
            num=i;
            break;
        }
    }
    if(num%n==0) c=num/n;
    else c=num/n+1;
    if(c%2==0) r=n-num%n+1;
    else r=num%n;
    cout<<c<<" "<<r;
    return 0;
}
