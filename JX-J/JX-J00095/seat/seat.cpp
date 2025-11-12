#include<bits/stdc++.h>
using namespace std;
int a[10005],b,c,n,m,x,y;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(b==a[i]){
            c=i;
        }
    }
    x=(c-1)/n+1;
    if(x%2!=0||x==1){
        y=c-(x-1)*n;
    }else{
        int t=c-(x-1)*n;
        y=m-t+1;
    }
    cout<<x<<" "<<y;
}
