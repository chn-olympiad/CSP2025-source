#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[1005]={0};
    for(int i=0;i<n*m;i++) cin>>a[i];
    int b=a[0];
    int c=0;
    sort(a,a+n*m,cmp);
    for(int i=0;i<=n*m;i++) {
        if(a[i]==b){
            c=i+1;
            break;
        }
    }
    int n1=0,m1=0;
    if(c%n!=0) m1=c/n+1;
    else m1=c/n;
    if(m1%2!=0){
        n1=c%n;
        if(n1==0) n1=n;
    }
    else {
        n1=n-c%n;
        if(n1==0) n1=1;
        if(n1==1) n1=n;
    }
    cout<<m1<<" "<<n1;
    return 0;
}
