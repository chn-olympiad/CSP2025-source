#include<bits/stdc++.h>
// #define int long long 
#define rep(i,x,y) for(int i=x;i<=y;i++)


using namespace std;

    int p=101;
unsigned long long qp(unsigned long long x,int k) {
    unsigned long long ans=1;
    while(k) {
        if(k%2==1) ans=ans*x;
        x=x*x;
        k/=2;
    }
    return ans;
}
int pww[5145141];
struct hash{
    unsigned long long hsh[5000005];
    unsigned long long gh(string s) {
        unsigned long long ret=0;
        for(int i=0;i<s.size();i++) {
            ret=ret*p+s[i]-'a'+1;
            hsh[i]=ret;
        }
        return ret;
    }
    unsigned long long gh2(int l,int r) {
        if(l==0) return hsh[r];
        return (hsh[r]-hsh[l-1]*qp(101,r-l+1));
    }
}Hx,Hy;
string s[514514][2];
int sm=0;
int n,q;
map<pair<unsigned long long,unsigned long long>,int>mp;
bool sln[5141554];
vector<int>nln;
// typedef pair<unsigned long long,unsigned long long> P;
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    // pww[0]=1;
    // rep(i,1,5000000) pww[i]=pww[i-1]*101;
// string u="aba";
// cout<<Hx.gh(u)<<'\n';
// cout<<Hx.gh2(0,0)<<' '<<Hx.gh2(1,2)<<endl;
    cin>>n>>q;
    rep(i,1,n) {
        cin>>s[i][1]>>s[i][2];
        mp[make_pair(Hx.gh(s[i][1]),Hy.gh(s[i][2]))]++;
     
        sln[(int)(s[i][1].size())]=1;
    }
    int nsz=0;
    rep(i,1,5000000){
        if(sln[i]) nln.push_back(i),nsz++;
    } 
    while(q--) {
        string x,y;
        cin>>x>>y;
        int l=5005005,r=0;
        int len=x.size();
       // x=' '+x,y=' '+y;
        if((int)x.size()!=(int)y.size()) {
            cout<<0<<'\n';
        } else{
            rep(i,0,len-1) {
                if(x[i]!=y[i]) {
                    l=min(l,i);
                    r=max(r,i);
                }
            }
            int nhx=Hx.gh(x);
            int nhy=Hy.gh(y);
            int ans=0;
            rep(i,0,l) {
                rep(jj,0,nsz-1) {
                    int j=i+nln[jj]-1;
                    if(r<=j&&j<len)
                    ans+=mp[make_pair(Hx.gh2(i,j),Hy.gh2(i,j))];
                }
            }
            cout<<ans<<'\n';
        }
    }

    return 0;
}