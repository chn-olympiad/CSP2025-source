#include<bits/stdc++.h>
using namespace std;
int sph(int l,int r,int a[]){
    int sum=0;
    for(int i=l;i<=r;i++){
        sum+=a[i];
    }return sum;
}
int mxi(int l,int r,int a[]){
    int sum=INT_MIN;
    for(int i=l;i<=r;i++){
        sum=max(sum,a[i]);
    }return sum;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+10];
    int mx=INT_MIN;
    int al=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(a[i],mx);
        al+=a[i];
    }int ans=0;

    if(n<3) cout<<0;
    else{
        if(n==3){
            if(al>mx*2) cout<<1; return 0;
        }
        for(int i=3;i<=n;i++){
            for(int j=1;j<=n-i;j++){
                al=sph(j,j+i,a);
                mx=mxi(j,j+i,a);
                cout<<mx<<endl;
                if(al>mx*2){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
