#include<bits/stdc++.h>
using namespace std;
struct S{
    long long x,y;
};
vector<S>vec;
long long f[500009];
long long n,k,a[500009],ans=1;
string dp[500009],sk;
string zhuan(long long a){
    if(a==0)
        return "0";
    string x="";
    long long l=a;
    while(l){
        x+=l%2+'0';
        l/=2;
    }
    return x;
}
string xo(string x,string y){
    string s,q;
    if(x.size()>y.size())
        s=x,q=y;
    else
        s=y,q=x;
    for(int i=0;i<q.size();++i){
        if(q[i]==s[i])
            s[i]='0';
        else
            s[i]='1';
    }
    return s;
}
void dfs(int step,long long num){
    ans=max(ans,num);
    for(int i=step+1;i<vec.size();++i){
        if(vec[i].x>vec[step].y)
            dfs(i,num+1);
    }
}
bool cmp(S a,S b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sk=zhuan(k);
    dp[1]=zhuan(a[1]);
    for(int i=2;i<=n;++i)
        dp[i]=xo(dp[i-1],zhuan(a[i]));
    for(int i=1;i<=n;++i){
        if(zhuan(a[i])==sk)
            vec.push_back({i,i});
        for(int j=i+1;j<=n;++j){
            string q;
            if(i==1)
                q=dp[j];
            else
                q=xo(dp[j],dp[i-1]);
            if(q==sk){
                vec.push_back({i,j});
            }
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    f[0]=1;
    for(int i=1;i<vec.size();++i){
        f[i]=1;
        for(int j=0;j<i;++j){
            if(vec[j].y<vec[i].x){
                f[i]=max(f[j]+1,f[i]);
            }
        }
        ans=max(f[i],ans);
    }
    cout<<ans;
    return 0;
}
