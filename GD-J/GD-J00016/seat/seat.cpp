#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],s=0,w=0,x,y;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1)s=a[i];
    }sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==s)w=i;
    }
    x=w/n;
    if(w%n!=0)x++;
    if(x%2==1&&(w%n!=0))y=w%n;
    else if(x%2==1)y=n;
    else y=n-w%n+1;
    cout<<x<<" "<<y;
    return 0;
}
