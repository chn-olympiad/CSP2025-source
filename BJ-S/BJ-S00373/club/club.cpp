#include<bits/stdc++.h>
using namespace std;
int n,ans,a1[10010],b1[10010],c1[10010];
void d(int a,int b,int c,int x,int an,int bn,int cn){
    if(x>n){ans=max(ans,a+b+c);return;}
    if(an<n/2)d(a+a1[x],b,c,x+1,an+1,bn,cn);
    if(bn<n/2)d(a,b+b1[x],c,x+1,an,bn+1,cn);
    if(cn<n/2)d(a,b,c+c1[x],x+1,an,bn,cn+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a1[i]>>b1[i]>>c1[i];
        d(0,0,0,0,0,0,0);
        cout<<ans<<endl;
    }

    return 0;
}