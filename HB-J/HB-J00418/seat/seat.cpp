#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,ans=1,maxx,x=1,y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i){
        cin>>a[i];
        if(i==1)r=a[1];
    }
    for(int i=1;i<=n*m;++i){
        for(int j=1;j<=n*m;++j){
            if(a[j]>maxx)maxx=a[j];
        }for(int k=1;k<=n*m;++k){
            if(a[k]==maxx){
                a[k]=-1;
            }
        }
        if(maxx==r)break;
        else{
            ans++;
            maxx=0;
        }
    }
    if(ans<=n){
        x=1,y=ans;
    }
    else{
        if(ans%n==0&&ans/n%2!=0){
            x=ans/n,y=n;
        }
        else if(ans%n==0&&ans/n%2==0){
            x=ans/n,y=1;
        }
        else{
            x=ans/n+1;
            if(x%2!=0){
                y=ans%n;
            }
            if(x%2==0){
                y=n-(ans%n)+1;
            }
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
