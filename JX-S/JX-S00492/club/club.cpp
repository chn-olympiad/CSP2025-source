#include<bits/stdc++.h>
using namespace std;
int t;
int n,lim;
int ans=0;
struct Man{
   int a;
   int b;
   int c;
};
bool cmp(Man x,Man y){
     return x.a>y.a;
}
Man m[200006];
int chan[6];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        lim=n/2;
        for(int i=1;i<=n;i++){
            cin>>m[i].a>>m[i].b>>m[i].c;
        }
       if(m[1].b==0&&m[1].c==0){
         sort(m+1,m+n+1,cmp);
         for(int i=1;i<=lim;i++){
            ans=ans+m[i].a;
         }
         cout<<ans;
         return 0;
       }
    }

return 0;
}
