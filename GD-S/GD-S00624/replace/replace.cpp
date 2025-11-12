#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7,M=5e6+7;
int n,Q;
using ull=unsigned long long;
const ull K=43;
ull pwK[M],hs[M];
struct arr{ull f,g1,g2,h;int l1,l2,l3;}str[N];
string A,B,S,T;
bool cmp(arr a,arr b){
    if(a.g1==b.g1){
        if(a.g2==b.g2) return a.l2<b.l2;
        return a.g2<b.g2;
    }
    return a.g1<b.g1;
}
ull geths(int l,int r){
    if(l>r) return 0;
    return hs[r]-hs[l-1]*pwK[r-l+1];
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    pwK[0]=1;
    for(int i=1;i<M;++i) pwK[i]=pwK[i-1]*K;
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>Q;
    for(int i=1;i<=n;++i){
        cin>>A>>B;
        if(A==B){continue;}
        int j=0,s=A.size()-1;
        for(;j<s&&A[j]==B[j];++j)str[i].f=str[i].f*K+(A[j]-'a'+1);
        str[i].l1=j;
        int k=s;
        for(;A[k]==B[k];--k)str[i].h=str[i].h+(A[k]-'a'+1)*pwK[s-k];
        str[i].l2=k-j+1;
        str[i].l3=s-k;
        for(;j<=k;++j){
            str[i].g1=str[i].g1*K+(A[j]-'a'+1);
            str[i].g2=str[i].g2*K+(B[j]-'a'+1);
        }
    }
    sort(str+1,str+n+1,cmp);
    while(Q--){
        arr p;
        cin>>S>>T;
        int j=0,siz=S.size()-1,k=siz;
        for(;j<siz&&S[j]==T[j];++j);
        for(;S[k]==T[k];--k);
        p.l1=j,p.l2=k-j+1,p.l3=siz-k;
        p.g1=p.g2=0;
        for(;j<=k;++j){
            p.g1=p.g1*K+(S[j]-'a'+1);
            p.g2=p.g2*K+(T[j]-'a'+1);
        }
        int s=lower_bound(str+1,str+n+1,p,cmp)-str;
        int t=upper_bound(str+1,str+n+1,p,cmp)-str;
        if(s>=t){cout<<0<<endl;continue;}
        hs[0]=S[0]-'a'+1;
        for(int i=1;i<=siz;++i)
            hs[i]=hs[i-1]*K+(S[i]-'a'+1);
        int ans=0;
        for(int i=s;i<t;++i){
            if(str[i].l1>p.l1||str[i].l2!=p.l2||str[i].l3>p.l3)
                continue;
            if(geths(p.l1-str[i].l1,p.l1-1)==str[i].f&&geths(k+1,k+str[i].l3)==str[i].h)
                ++ans;
        }
        cout<<ans<<endl;
    }
}