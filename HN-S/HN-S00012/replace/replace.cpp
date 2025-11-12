#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
const int LL=5e6;
const int base=43;
const int mod=998244853;
const int B=800;
int n,q,ba[LL+7],tot;
int pls(int a,int b){ return a+b>=mod?a+b-mod:a+b; }
int sub(int a,int b){ return a>=b?a-b:a-b+mod; }
int mul(int a,int b){ return 1ll*a*b%mod; }
unordered_map<int,int>mp;
vector<int> v[maxn];
string s[maxn][2];
int ha[maxn][2],L[maxn],R[maxn],ht[LL+7];
int qpow(int a,int b){
    int res=1;
    for(;b;b>>=1,a=mul(a,a)) if(b&1) res=mul(res,a);
    return res;
}
int getha0(int l,int r){
    l++; r++;
    return sub(ht[r],mul(ht[l-1],ba[r-l+1]));
}
// 喜欢考字符串我直接不会AC
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q; ba[0]=1;
    for(int i=1;i<=LL;i++) ba[i]=mul(ba[i-1],base);
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1]; 
        int len=s[i][0].length();
        int l=-1,r=len;
        while(l+1<len&&s[i][0][l+1]==s[i][1][l+1]) l++;
        if(l==len-1) continue;
        while(r-1>=0&&s[i][0][r-1]==s[i][1][r-1]) r--;
        int has=0; 
        for(int j=l+1;j<r;j++){
            has=pls(mul(has,base),s[i][0][j]-'a'+1);
        }
        for(int j=l+1;j<r;j++){
            has=pls(mul(has,base),s[i][1][j]-'a'+1);
        }
        if(!mp[has]) mp[has]=++tot;
        v[mp[has]].push_back(i);
        for(int j=0;j<=l;j++){
            L[i]++;
            ha[i][0]=pls(mul(ha[i][0],base),s[i][0][j]-'a'+1);
        }
        for(int j=r;j<len;j++){
            R[i]++;
            ha[i][1]=pls(mul(ha[i][1],base),s[i][0][j]-'a'+1);
        }
        // cerr<<L[i]<<' '<<R[i]<<'\n';
        // cerr<<ha[i][0]<<' '<<ha[i][1]<<'\n';
    }
    for(int i=1;i<=q;i++){
        string t1,t2;
        cin>>t1>>t2;
        int len=t1.length(),Len=t2.length();
        if(len!=Len){
            cout<<"0\n";
            continue;
        }
        int l=-1,r=len;
        while(l+1<len&&t1[l+1]==t2[l+1]) l++;
        while(r-1>=0&&t1[r-1]==t2[r-1]) r--;
        int has=0;
        for(int j=l+1;j<r;j++){
            has=pls(mul(has,base),t1[j]-'a'+1);
        }
        for(int j=l+1;j<r;j++){
            has=pls(mul(has,base),t2[j]-'a'+1);
        }
        if(!mp[has]){
            cout<<"0\n";
            continue;
        }

        for(int j=0;j<len;j++){
            ht[j+1]=pls(mul(ht[j],base),t1[j]-'a'+1);
        }
        int z=mp[has],cnt=0;
        // if(v[z].size()<=B
        for(int j:v[z]){
            if(l-L[j]+1<0||r+R[j]-1>=len) continue; 
            if(ha[j][0]==getha0(l-L[j]+1,l)&&ha[j][1]==getha0(r,r+R[j]-1)) cnt++;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}