#include<bits/stdc++.h>
using namespace std;
int n,n2,ans;

struct code{
    int b1,b2,b3;
    short c1,c2,c3;
    bool tf=false;
};
bool cmp1(code x,code y){
    return x.b1>y.b1;
}
code a[100010];
void solve(){
    cin>>n;
    if(n==0){
        return;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].b1;
        a[i].c1=1;
        cin>>a[i].b2;
        a[i].c2=2;
        cin>>a[i].b3;
        a[i].c3=3;
        a[i].tf=false;
        if(a[i].b1<a[i].b2){
            if(a[i].b2<a[i].b3){
                swap(a[i].b2,a[i].b3);
                swap(a[i].b1,a[i].b2);
                swap(a[i].c2,a[i].c3);
                swap(a[i].c1,a[i].c2);
            }else{
                swap(a[i].b1,a[i].b2);
                swap(a[i].c1,a[i].c2);
            }
        }else{
            if(a[i].b2<a[i].b3){
              swap(a[i].b2,a[i].b3);
              swap(a[i].c2,a[i].c3);
              if(a[i].b1<a[i].b2){
                swap(a[i].b1,a[i].b2);
                swap(a[i].c1,a[i].c2);
              }
            }
        }
    }
    sort(a+1,a+n+1,cmp1);
    n2=n/2;
    for(int i=1;i<=n;i++){
        cout<<a[i].b1<<' '<<a[i].b2<<' '<<a[i].b3<<endl;
        cout<<a[i].c1<<' '<<a[i].c2<<' '<<a[i].c3<<endl;
    }
    cout<<endl;
    int sum[4]={0,0,0,0};
    for(int i=1;i<=n;i++){
        if(sum[a[i].c1]>=n2){
            if(sum[a[i].c2]>=n2){
                sum[a[i].c3]++;
                ans+=a[i].b3;
            }else{
                sum[a[i].c2]++;
                ans+=a[i].b2;
            }
        }else{
            sum[a[i].c1]++;
            ans+=a[i].b1;
            a[i].tf=true;
        }
    }
    for(int i=1;i<=3;i++){
        cout<<sum[i]<<endl;
    }
    cout<<ans;
}
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans=0;
        solve();
    }
    return 0;
}
