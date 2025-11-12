#include<bits/stdc++.h>
#define PII pair<int,int>
#define fir first
#define sec second
#define int long long
using namespace std;
const int mod1=998244353,mod2=1e9+7;
const int b1=37,b2=29;
int n,Q,cnt,p1[5000005],p2[5000005];
string x,y;
map<array<int,6>,vector<PII> > mp;
map<array<int,8>,int> mp2;
map<array<int,2>,int> mp1;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>Q;
    p1[0]=p2[0]=1;
    for(int i=1;i<=n;i++){
        p1[i]=p1[i-1]*b1%mod1;
        p2[i]=p2[i-1]*b2%mod2;
    }
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        int l=1,len=x.size();
        int r=len;
        x=' '+x;
        y=' '+y;
        while(l<=len&&x[l]==y[l]){
            l++;
        }
        while(r>=1&&x[r]==y[r]){
            r--;
        }
        if(l>r){
            cnt++;
        }else{
            int t1=0,t2=0;
            for(int j=l;j<=r;j++){
                t1=(t1*b1%mod1+x[j]-'a'+1)%mod1;
                t2=(t2*b2%mod2+x[j]-'a'+1)%mod2;
            }
            int t3=0,t4=0;
            for(int j=l;j<=r;j++){
                t3=(t3*b1%mod1+y[j]-'a'+1)%mod1;
                t4=(t4*b2%mod2+y[j]-'a'+1)%mod2;
            }
            int t5=0,t6=0;
            for(int j=l-1;j>=1;j--){
                t5=(t5*b1%mod1+x[j]-'a'+1)%mod1;
                t6=(t6*b2%mod2+x[j]-'a'+1)%mod2;
            }
            int t7=0,t8=0;
            for(int j=r+1;j<=len;j++){
                t7=(t7*b1%mod1+x[j]-'a'+1)%mod1;
                t8=(t8*b2%mod2+x[j]-'a'+1)%mod2;
            }
            mp2[{t1,t2,t3,t4,t5,t6,t7,t8}]++;
            mp[{t1,t2,t3,t4,t7,t8}].push_back({t5,t6});
        }
    }
    if(Q==1){
        cin>>x>>y;
        int l=1,len=x.size();
        int r=len;
        x=' '+x;
        y=' '+y;
        while(l<=len&&x[l]==y[l]){
            l++;
        }
        while(r>=1&&x[r]==y[r]){
            r--;
        }
        int t1=0,t2=0;
        for(int j=l;j<=r;j++){
            t1=(t1*b1%mod1+x[j]-'a'+1)%mod1;
            t2=(t2*b2%mod2+x[j]-'a'+1)%mod2;
        }
        int t3=0,t4=0;
        for(int j=l;j<=r;j++){
            t3=(t3*b1%mod1+y[j]-'a'+1)%mod1;
            t4=(t4*b2%mod2+y[j]-'a'+1)%mod2;
        }
        int t7=0,t8=0,ans=mp2[{t1,t2,t3,t4,0,0,0,0}];
        int t5=0,t6=0;
        for(int j=l-1;j>=1;j--){
            t5=(t5*b1%mod1+x[j]-'a'+1)%mod1;
            t6=(t6*b2%mod2+x[j]-'a'+1)%mod2;
            ans+=mp2[{t1,t2,t3,t4,t5,t6,0,0}];
            mp1[{t5,t6}]++;
        }
        for(int i=r+1;i<=len;i++){
            t7=(t7*b1%mod1+x[i]-'a'+1)%mod1;
            t8=(t8*b2%mod2+x[i]-'a'+1)%mod2;
            ans+=mp2[{t1,t2,t3,t4,0,0,t7,t8}];
            for(auto v:mp[{t1,t2,t3,t4,t7,t8}]){
                if(mp1[{v.fir,v.sec}]) ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    while(Q--){
        cin>>x>>y;
        int l=1,len=x.size();
        int r=len;
        x=' '+x;
        y=' '+y;
        while(l<=len&&x[l]==y[l]){
            l++;
        }
        while(r>=1&&x[r]==y[r]){
            r--;
        }
        int t1=0,t2=0;
        for(int j=l;j<=r;j++){
            t1=(t1*b1%mod1+x[j]-'a'+1)%mod1;
            t2=(t2*b2%mod2+x[j]-'a'+1)%mod2;
        }
        int t3=0,t4=0;
        for(int j=l;j<=r;j++){
            t3=(t3*b1%mod1+y[j]-'a'+1)%mod1;
            t4=(t4*b2%mod2+y[j]-'a'+1)%mod2;
        }
        int t7=0,t8=0,ans=mp2[{t1,t2,t3,t4,0,0,0,0}];
        int t5=0,t6=0;
        for(int j=l-1;j>=1;j--){
            t5=(t5*b1%mod1+x[j]-'a'+1)%mod1;
            t6=(t6*b2%mod2+x[j]-'a'+1)%mod2;
            ans+=mp2[{t1,t2,t3,t4,t5,t6,0,0}];
        }
        for(int i=r+1;i<=len;i++){
            t7=(t7*b1%mod1+x[i]-'a'+1)%mod1;
            t8=(t8*b2%mod2+x[i]-'a'+1)%mod2;
            ans+=mp2[{t1,t2,t3,t4,0,0,t7,t8}];
            t5=0,t6=0;
            for(int j=l-1;j>=1;j--){
                t5=(t5*b1%mod1+x[j]-'a'+1)%mod1;
                t6=(t6*b2%mod2+x[j]-'a'+1)%mod2;
                ans+=mp2[{t1,t2,t3,t4,t5,t6,t7,t8}];
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}
