#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
struct nn{
    int a,b,c,v;
}as[N];
int ks[5];
bool cmp(nn a,nn s){
    return a.v<s.v;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        int ans=0;
        memset(ks,0,sizeof ks);
        cin>>n;
        vector<nn>s[5];
        for(int i=1;i<=n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            int k1=0,k2=0,p;
            k1=max(a,max(b,c));
            ans+=k1;
            if(k1==a){
                p=1;
                k2=max(b,c);
            }
            if(k1==b){
                p=2;
                k2=max(a,c);
            }
            if(k1==c){
                p=3;
                k2=max(a,b);
            }
            int v=k1-k2;
            as[i]={a,b,c,v};
            s[p].push_back(as[i]);
            ks[p]++;
        }
        int ma=max(ks[1],max(ks[2],ks[3]));
        if(ma>n/2){
            int p=0;
            if(ma==ks[1]){
                p=1;
            }
            if(ma==ks[2]){
                p=2;
            }
            if(ma==ks[3]){
                p=3;
            }
            sort(s[p].begin(),s[p].end(),cmp);
            for(int i=0;i<ma-n/2;i++){
                ans-=s[p][i].v;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
