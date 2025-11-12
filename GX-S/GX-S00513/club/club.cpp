#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct club{
    int s1,s2,s3;
}a[200005];
long long res;
void dfs(int ps,long long ans,int sp1,int sp2,int sp3){
    //cout<<"sp1:"<<sp1<<" sp2:"<<sp2<<" sp3:"<<sp3<<endl;
    if((sp1>n/2)==true||(sp2>n/2)==true||(sp3>n/2)==true){
        return;
    }
    else if(ps==n){
        //cout<<sp1<<" "<<n/2<<endl;
        //cout<<"ans:"<<ans<<endl;
        res=max(ans,res);
    }
    else{
        dfs(ps+1,ans+a[ps+1].s1,sp1+1,sp2,sp3);
        dfs(ps+1,ans+a[ps+1].s2,sp1,sp2+1,sp3);
        dfs(ps+1,ans+a[ps+1].s3,sp1,sp2,sp3+1);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        res=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].s1>>a[i].s2>>a[i].s3;
        }
        dfs(0,0,0,0,0);
        cout<<res<<endl;
    }
    return 0;
}
