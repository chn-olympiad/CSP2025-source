#include<bits/stdc++.h>
using namespace std;
int n,m,k,r,c,a[105];
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
    k=a[1];r=c=1;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;a[i]!=k;i++){
        if(c%2)r++;
        else r--;
        if(r==n+1)r=n,c++;
        if(r==0)r=1,c++;
    }
    cout<<c<<" "<<r;
    return 0;
}
