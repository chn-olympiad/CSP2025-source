#include<bits/stdc++.h>
using namespace std;
int a[5010];
long long jc(int x){
    long long ans=1;
    for(int i=1;i<=x;i++){
        ans=ans*i%998;
        ans%=244;
        ans%=353;
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    //cout<<"t";
    int n;
    cin>>n;
    bool fa=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) fa=0;
    }
    if(n<3) {
        cout<<0;
        return 0;
    }
    if(n==3){
        sort(a+1,a+n+1);
        if(a[1]+a[2]+a[3]>a[3]*2) cout<<1;
        else cout<<0;
        return 0;
    }
    if(fa){
        int ans=0;
        for(int k=3;k<=n;k++){
            long long g=jc(n)/jc(n-k)/jc(k);
            //cout<<k<<' '<<g<<endl;
            g%=998;
            g%=244;
            g%=353;
            ans=ans+g;
            ans%=998;
            ans%=244;
            ans%=353;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    int l=1,r=1;
    int add=0;
    int cnt=n;
    int ans1=0;
    for(;cnt>=3;cnt--)
        while(r<=cnt){
            if(add>a[cnt]*2){
                int res=(cnt-r+1)%998;
                res%=244;
                res%=353;
                ans1=ans1+res;
                ans1=ans1%998%244%353;
                l++;
                add-=a[l];
            }
            r++;
            add+=a[r];
        }
    cout<<ans1;
    return 0;
}
