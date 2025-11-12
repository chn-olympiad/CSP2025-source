#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n;
struct q{
    int a,b,c;
};
q r[N];
bool flag;
bool flag2;
int ans=0;
bool cmp(q x,q y){
    return x.a>y.a;
}
bool cmp2(q x,q y){
    return x.b>y.b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        flag=1;
        flag2=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>r[i].a>>r[i].b>>r[i].c;
            if(r[i].b!=0 || r[i].c!=0){
                flag=0;
            }
            if(r[i].c!=0){
                flag2=0;
            }
        }
        ans=0;
        if(flag==1){
            sort(r+1,r+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=r[i].a;
            }
            cout<<ans<<endl;
        }
        else if(flag2==1){
            sort(r+1,r+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=r[i].a;
                ans+=r[n-i+1].b;
            }
            int ans1=0;
            sort(r+1,r+n+1,cmp2);
            for(int i=1;i<=n/2;i++){
                ans1+=r[i].b;
                ans1+=r[n-i+1].a;
            }
            ans=max(ans,ans1);
            cout<<ans<<endl;
        }
    }
    return 0;
}
