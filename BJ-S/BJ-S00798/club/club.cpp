#include<bits/stdc++.h>
using namespace std;
struct cha{
    int ab,mode;
};
bool cmd1(cha a,cha b){
    if(a.mode==2||b.mode==2) return a.mode<b.mode;
    else return a.ab<b.ab;
}
bool cmd2(cha a,cha b){
    if(a.mode==1||b.mode==1) return a.mode>b.mode;
    else return a.ab<b.ab;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==2){
            int a[4],b[4],m1,m2,ans=0;
            for(int i=1;i<=3;i++) cin>>a[i];
            for(int i=1;i<=3;i++) cin>>b[i];
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(i==j) continue;
                    ans=max(ans,a[i]+b[j]);
                }
            }
            cout<<ans;
            continue;
        }
        int a[n+1],b[n+1],c[n+1],ans=0,xa=0,xb=0;
        cha a_b[n+1];
        for(int i=1;i<=n;i++) {
            cin>>a[i]>>b[i]>>c[i];
            a_b[i].ab=abs(a[i]-b[i]);
            if(a[i]>b[i]) a_b[i].mode=1;
            else a_b[i].mode=2;
            ans+=max(a[i],b[i]);
            if(a[i]>b[i]) xa++;
            else xb++;
        }
        if(xa>xb) sort(a_b+1,a_b+n+1,cmd1);
        else sort(a_b,a_b+n+1,cmd2);
        for(int i=1;i<=(max(xa,xb)-n/2);i++) {
            ans-=a_b[i].ab;
        }
        cout<<ans<<endl;
    }
    return 0;
}
