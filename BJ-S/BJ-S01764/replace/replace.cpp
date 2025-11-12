#include<bits/stdc++.h>
using namespace std;
int n,m;
string s0[200],s1[200];
int exis[1005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s0[i]>>s1[i];
    while(m--){
        int ans=0;
        string t0,t1;
        cin>>t0>>t1;
        int l=2e9,r=0;
        for(int i=0;i<t0.size();i++){
            if(t0[i]!=t1[i]){
                l=min(l,i);
                r=max(r,i);
            }
        }
//        cout<<"########## "<<t0<<" "<<t1<<endl;
        for(int i=1;i<=n;i++){
//            cout<<s0[i]<<" "<<s1[i]<<endl;
            memset(exis,0,sizeof(exis));
            int x=-1;
            while(1){
                x=t0.find(s0[i],x+1);
//        cout<<"0  "<<x<<endl;
                if(x<0||x>=t0.size())break;
                exis[x]=1;
            }
            x=-1;
            while(1){
                x=t1.find(s1[i],x+1);
//        cout<<"1  "<<x<<endl;
                if(x<0||x>=t1.size())break;
                if(r>x+s0[i].size()-1)continue;
                if(l<x)continue;
                ans+=exis[x];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
