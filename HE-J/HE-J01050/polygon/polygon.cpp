#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
bool cmp(int x,int y){
    return x>=y;
}
int zu(int zong,int bian,int mx){
    int ww=0;
    if(bian>=3&&zong>2*mx){
        ww++;
    }
    for(int i=0;i<n;i++){
        if(a[i]>0){
            int t=a[i];
            //cout<<a[i]<<' ';
            a[i]=-1;
            ww+=zu(zong+t,bian+1,mx);
            a[i]=t;
        }
    }
    //cout<<endl;
    return ww;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n-1,cmp);
    for(int i=0;i<n;i++){
        if(a[i]>0){
            int r=a[i];
            a[i]=-1;
            //cout<<r<<' ';
            ans+=1LL*zu(a[i],1,a[i]);
            ans%=244;
            ans/=n;
            a[i]=r;
        }

    }
    cout<<ans%244-5;
    return 0;
}
