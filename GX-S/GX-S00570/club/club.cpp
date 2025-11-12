#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int x1,x2,x3;
long long ans=0;
int a[100009];
bool cmp(int x,int y){
return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while(T--){
            memset(a,0,sizeof(a));
        ans=0;
        cin>>n;
        if(n==2){
            int a,b,c,d,e,f;
            cin>>a>>b>>c>>d>>e>>f;
            int ans=max(a+e,max(a+f,max(b+d,max(b+f,max(c+d,c+e)))));
            cout<<ans<<'\n';
        }
        else{
        for(int i=1,k,l;i<=n;i++) cin>>a[i]>>k>>l;
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n/2;i++) ans+=a[i];
        cout<<ans<<'\n';
        }
    }
    return 0;
}
