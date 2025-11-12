#include<bits/stdc++.h>
using namespace std;
int n,m,s[15][15],a[105],j,g,x,c,r;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    j=n*m;
    for(int i=1;i<=j;i++){
        cin>>a[i];
        g=a[1];
    }
    sort(a+1,a+j+1,cmp);
    for(int i=1;i<=j;i++){
        if(a[i]==g){
            x=i;
            break;
        }
    }
    if(x/n%2==0&&x%n!=0){
        r=x%n;
        c=x/n+1;
    }
    else if(x/n%2!=0&&x%n==0){
        r=n;
        c=x/n;
    }
    else if(x/n%2!=0&&x%n!=0){
        r=n-x%n+1;
        c=x/n+1;
    }
    else if(x/n%2==0&&x%n==0){
        r=1;
        c=x/n;
    }
    cout<<c<<" "<<r;
    return 0;
}
