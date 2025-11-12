/*
实在是没思路啊啊啊！！！
*/
#include<bits/stdc++.h>
using namespace std;
long long t,n,a1[100002],a2[100002],a3[100002],c1,c2,c3,cnt,ans;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    for(int i=1;i<=t;i++){
        scanf("%lld",&n);
        long long sx=n/2;
        c1=0;c2=0;c3=0;ans=0;
        for(int j=1;j<=n;j++){
            cin>>a1[j]>>a2[j]>>a3[j];
        }
        sort(a1+1,a1+n+1,cmp);
        sort(a2+1,a2+n+1,cmp);
        sort(a3+1,a3+n+1,cmp);
        for(int j=1;j<=sx;j++){
            c1+=a1[j];
            c2+=a2[j];
            c3+=a3[j];
        }
        cnt=max(c1,max(c2,c3));
        ans=cnt;
        if(c1!=cnt){
            ans+=a1[1];
        }
        if(c2!=cnt){
            ans+=a2[1];
        }
        if(c3!=cnt){
            ans+=a3[1];
        }
        cout<<ans<<endl;
    }
    return 0;
}
