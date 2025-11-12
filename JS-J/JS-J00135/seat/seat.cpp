#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[105];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int rx=a[1];
    sort(a+1,a+n*m+1,cmp);
    int c=1,r=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]==rx)break;
        if(c%2==1)r++;
        else r--;
        if(r==0){
            r=1;
            c++;
        }else if(r==n+1){
            r=n;
            c++;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
