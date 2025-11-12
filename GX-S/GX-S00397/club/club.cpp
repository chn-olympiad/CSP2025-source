#include<bits/stdc++.h>
using namespace std;
struct club{
    int a,b,c;
};
int t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n,ans=0;
        cin>>n;
        int cnt=n/2,mx[n];
        club m[n];
        for(int i=1;i<=n;i++){
            cin>>m[i].a>>m[i].b>>m[i].c;
            mx[i]=0;
            mx[i]=max(mx[i],max(m[i].a,max(m[i].b,m[i].c)));
            ans+=mx[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}
