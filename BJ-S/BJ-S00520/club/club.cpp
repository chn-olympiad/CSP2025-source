#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e6;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,m1,m2,m3,ans=0,sum=0,res=0,s1=0,s2=0,s3=0;
    cin>>t;
    for(int z=1;z<=t;z++){
        cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m1>>m2>>m3;
        if(m1>m2>m3){
            ans+=m1;
            s1++;
        }else if(m2>m1>m3){
            sum+=m2;
            s2++;
        }else if(m3>m2>m1){
            res+=m3;
            s3++;
        }else if(m1>m3>m2){
            ans+=m1;
            s1++;
        }else if(m2>m3>m1){
            sum+=m2;
            s2++;
        }else if(m3>m1>m2){
            res+=m3;
            s3++;
        }
    }
    int k=ans+sum+res;
    if(s1<=n/2&&s2<=n/2&&s3<=n/2){
        cout<<k<<endl;
    }
}
    return 0;
}
