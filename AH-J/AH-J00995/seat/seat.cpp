#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int cnt=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(cnt==a[i]){
            cnt=i;
        }
    }
    int c,r;
    c=(cnt-1)/n+1;
    if(c%2==1){
        r=(cnt-1)%m+1;
    }else{
        r=m-((cnt-1)%m+1)+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
