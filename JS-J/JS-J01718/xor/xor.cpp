#include<bits/stdc++.h>
using namespace std;
void read(int &x){
    char c=getchar();
    bool f=0;
    while(c<'0'){
        if(c=='-') f=1;
        c=getchar();
    }
    x=0;
    while(c>='0'){
        x=x*10+c-'0';
        c=getchar();
    }
    if(f) x=-x;
}
class sol1{
public:
    vector<bitset<22>> a;
    bitset<22> k;
    vector<vector<int>> pre;
    bool check(int l,int r){//20
        bitset<22> t;
        for(int m=0;m<=21;m++){
            int x=pre[r][m]-pre[l-1][m];
            if(x&1) t[m]=1;
        }
        return k==t;
    }
    void solve(int n,int sk,vector<int> &sa){
        a.resize(n+1);
        for(int i=1,x;i<=n;i++){//20n
            x=sa[i];
            for(int m=0;m<=21;m++){
                if(x&(1<<m)) a[i][m]=1;
            }
        }
        for(int m=0;m<=21;m++) if(sk&(1<<m)) k[m]=1;
        pre.resize(n+1,vector<int>(22,0));
        for(int i=1;i<=n;i++){
            for(int m=0;m<=21;m++){
                pre[i][m]=pre[i-1][m];
                if(a[i][m]) pre[i][m]++;
            }
        }
        int ans=0;
        vector<int> dp(n+1,0),lst(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            lst[i]=lst[i-1];
            for(int j=lst[i]+1;j<=i;j++){
                if(check(j,i)){
                    dp[i]++,lst[i]=i;
                    break;
                }
            }
        }
        cout<<dp[n]<<'\n';    
    }
};
class sol2{
public:
    vector<bitset<2>> a;
    bitset<2> k;
    vector<vector<int>> pre;
    bool check(int l,int r){//2
        bitset<2> t;
        for(int m=0;m<=1;m++){
            int x=pre[r][m]-pre[l-1][m];
            if(x&1) t[m]=1;
        }
        return k==t;
    }
    void solve(int n,int sk,vector<int> &sa){
        a.resize(n+1);
        for(int i=1,x;i<=n;i++){//2n
            x=sa[i];
            for(int m=0;m<=1;m++){
                if(x&(1<<m)) a[i][m]=1;
            }
        }
        for(int m=0;m<=1;m++) if(sk&(1<<m)) k[m]=1;
        pre.resize(n+1,vector<int>(2,0));
        for(int i=1;i<=n;i++){
            for(int m=0;m<=1;m++){
                pre[i][m]=pre[i-1][m];
                if(a[i][m]) pre[i][m]++;
            }
        }
        int ans=0;
        vector<int> dp(n+1,0),lst(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            lst[i]=lst[i-1];
            for(int j=lst[i]+1;j<=i;j++){
                if(check(j,i)){
                    dp[i]++,lst[i]=i;
                    break;
                }
            }
        }
        cout<<dp[n]<<'\n';    
    }
};
class sol3{
public:
    vector<bitset<10>> a;
    bitset<10> k;
    vector<vector<int>> pre;
    bool check(int l,int r){//20
        bitset<10> t;
        for(int m=0;m<=9;m++){
            int x=pre[r][m]-pre[l-1][m];
            if(x&1) t[m]=1;
        }
        return k==t;
    }
    void solve(int n,int sk,vector<int> &sa){
        a.resize(n+1);
        for(int i=1,x;i<=n;i++){//20n
            x=sa[i];
            for(int m=0;m<=9;m++){
                if(x&(1<<m)) a[i][m]=1;
            }
        }
        for(int m=0;m<=9;m++) if(sk&(1<<m)) k[m]=1;
        pre.resize(n+1,vector<int>(10,0));
        for(int i=1;i<=n;i++){
            for(int m=0;m<=9;m++){
                pre[i][m]=pre[i-1][m];
                if(a[i][m]) pre[i][m]++;
            }
        }
        int ans=0;
        vector<int> dp(n+1,0),lst(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            lst[i]=lst[i-1];
            for(int j=lst[i]+1;j<=i;j++){
                if(check(j,i)){
                    dp[i]++,lst[i]=i;
                    break;
                }
            }
        }
        cout<<dp[n]<<'\n';    
    }
};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,sk;
    read(n);read(sk);
    vector<int> sa(n+1);
    bool spb=true,spc=true;
    for(int i=1;i<=n;i++){
        read(sa[i]);
        if(sa[i]>255) spc=false;
        if(sa[i]>1) spb=false;
    }
    if(spb){
        sol2 s;
        s.solve(n,sk,sa);
        return 0;
    }
    if(spc){
        sol3 s;
        s.solve(n,sk,sa);
        return 0;
    }
    sol1 s;
    s.solve(n,sk,sa);
    return 0;
}