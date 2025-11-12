#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,limit,degree;
ll a[100005];
bool flag,flag1=1;
ll b[100005];
ll c[100005];
void solve(){
    for(ll i=1;i<=n;i++){
        a[i]=0;
        b[i]=0;
    }
    cin>>n;
    flag=0;
    flag1=1;
    limit=n/2;
    degree=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        if(b[i]!=0)flag=1;
    }
    if(n==2){
        if(a[1]>=b[1]&&b[1]>=c[1]&&flag1){
            degree+=a[1];
            flag1=0;
        }
        if(a[1]>=c[1]&&c[1]>=b[1]&&flag1){
            degree+=a[1];
            flag1=0;
        }
        if(b[1]>=a[1]&&a[1]>=c[1]&&flag1){
            degree+=b[1];
            flag1=0;
        }
        if(b[1]>=c[1]&&c[1]>=a[1]&&flag1){
            degree+=b[1];
            flag1=0;
        }
        if(c[1]>=b[1]&&b[1]>=a[1]&&flag1){
            degree+=c[1];
            flag1=0;
        }
        if(c[1]>=a[1]&&a[1]>=b[1]&&flag1){
            degree+=c[1];
            flag1=0;
        }
        flag1=1;
        if(a[2]>=b[2]&&b[2]>=c[2]&&flag1){
            degree+=a[2];
            flag1=0;
        }
        if(a[2]>=c[2]&&c[2]>=b[2]&&flag1){
            degree+=a[2];
            flag1=0;
        }
        if(b[2]>=a[2]&&a[2]>=c[2]&&flag1){
            degree+=b[2];
            flag1=0;
        }
        if(b[2]>=c[2]&&c[2]>=a[2]&&flag1){
            degree+=b[2];
            flag1=0;
        }
        if(c[2]>=b[2]&&b[2]>=a[2]&&flag1){
            degree+=c[2];
            flag1=0;
        }
        if(c[2]>=a[2]&&a[2]>=b[2]&&flag1){
            degree+=c[2];
            flag1=0;
        }
        cout<<degree<<endl;
        return;
    }
    if(!flag){
        sort(a+1,a+1+n,greater<int>());
        for(ll i=1;i<=limit;i++){
            degree+=a[i];
        }
        cout<<degree<<endl;
    }else{
        for(ll i=1;i<=n;i++){
            if(a[i]>=b[i]){
                degree+=a[i];
            }else{
                degree+=b[i];
            }
        }
        cout<<degree<<endl;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(ll i=1;i<=t;i++)solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
