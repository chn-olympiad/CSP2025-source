#include<bits/stdc++.h>
#define int long long
const int B=13331;
using namespace std;
using ull=unsigned long long;
// #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin)),p1==p2?EOF:*p1++)
// char buf[1<<23],*p1=buf,*p2=buf;
int read(){char c=getchar();int p=0,flg=1;while(c<'0'||c>'9'){if(c=='-') flg=-1;c=getchar();}while(c>='0'&&c<='9'){p=p*10+c-'0';c=getchar();}return p*flg;}
int n,m;ull pw[5000010],hS[5000010],hT[5000010];struct Info{int l,r,n;ull As,At,Bs,Bt,Cs,Ct;}a[200010];map<array<ull,2>,vector<int>>mp;
signed main(){
    freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
    n=read();m=read();
    for(int i=pw[0]=1;i<=5e6;i++) pw[i]=pw[i-1]*B;
    for(int i=1;i<=n;i++){
        string s,t;cin>>s>>t;a[i].n=s.size();s=" "+s;t=" "+t;if(s==t) continue;
        a[i].l=1;a[i].r=a[i].n;
        for(;s[a[i].l]==t[a[i].l];a[i].l++);
        for(;s[a[i].r]==t[a[i].r];a[i].r--);
        for(int j=1;j<a[i].l;j++){
            a[i].As=a[i].As*B+s[j];
            a[i].At=a[i].At*B+t[j];
        }
        for(int j=a[i].l;j<=a[i].r;j++){
            a[i].Bs=a[i].Bs*B+s[j];
            a[i].Bt=a[i].Bt*B+t[j];
        }
        for(int j=a[i].r+1;j<=a[i].n;j++){
            a[i].Cs=a[i].Cs*B+s[j];
            a[i].Ct=a[i].Ct*B+t[j];
        }
        mp[{a[i].Bs,a[i].Bt}].push_back(i);
    }
    while(m--){
        string S,T;cin>>S>>T;int N=S.size(),L=1,R=N,ans=0;S=" "+S;T=" "+T;
        for(;S[L]==T[L];L++);
        for(;S[R]==T[R];R--);
        for(int i=1;i<S.size();i++) hS[i]=hS[i-1]*B+S[i],hT[i]=hT[i-1]*B+T[i];
        auto calcS=[&](int l,int r){return hS[r]-hS[l-1]*pw[r-l+1];};
        auto calcT=[&](int l,int r){return hT[r]-hT[l-1]*pw[r-l+1];};
        for(auto i:mp[{calcS(L,R),calcT(L,R)}]){
            if(a[i].l>L) continue;
            if(a[i].As^calcS(L-a[i].l+1,L-1)||a[i].At^calcT(L-a[i].l+1,L-1)) continue;
            if(a[i].n-a[i].r>N-R) continue;
            if(a[i].Cs^calcS(R+1,R+a[i].n-a[i].r)||a[i].Ct^calcT(R+1,R+a[i].n-a[i].r)) continue;
            ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}