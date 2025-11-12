#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long s[5005];
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        s[i]=a[i]+s[i-1];
    }
    if(n<3) cout<<0;
    else if(n==3){
        if(s[2]>a[3]) cout<<1;
        else cout<<0;
    }
    else{
        bool flag=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=1) flag=1;
        }
        if(!flag){
            long long ans1=0;
            for(int i=3;i<=n;i++){
                long long cnt1=1,cnt2=1;
                for(int j=n;j>=n-i+1;j--) cnt1*=j;
                for(int j=1;j<=i;j++) cnt2*=j;
                ans1+=cnt1/cnt2;
            }
            cout<<ans1%998%244%353;
        }
        else cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
