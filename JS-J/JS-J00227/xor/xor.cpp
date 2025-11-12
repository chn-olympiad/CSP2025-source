#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll ans=LONG_LONG_MIN;
ll a[500005];
ll myxor(ll a,ll b){
    if(a==b){
        return 0;
    }
    string str1,str2;
    while(a){
        ll x=a%2;
        str1=(char)(x+'0')+str1;
        a/=2;
    }
    while(b){
        ll x=b%2;
        str2=(char)(x+'0')+str2;
        b/=2;
    }
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    string ans;
    for(ll i=0;i<min(str1.size(),str2.size());i++){
        if(str1[i]==str2[i]){
            ans+='0';
        }else{
            ans+='1';
        }
    }
    ll len1=str1.size();
    ll len2=str2.size();
    for(int i=1;i<=abs(len1-len2);i++){
        ans+='1';
    }
    ll s=1;
    ll xorans=0;
    for(int i=0;i<ans.size();i++){
        xorans+=s*(int)(ans[i]-'0');
        s*=2;
    }
    return xorans;
}
void dfs(ll dep,ll s,bool cx,ll qj){
    if(dep>n){
        if(s==k){
            qj++;
        }
        if(s==k||s==-1){
            ans=max(ans,qj);
            //cout<<"OK\n";
        }
        return;
    }else{
        if(cx==1){
          if(s==k){
            //cout<<dep<<"duan\n";
            dfs(dep+1,-1,1,qj+1);
            dfs(dep+1,a[dep],1,qj+1);
          }
          dfs(dep+1,myxor(s,a[dep]),1,qj);
        }else{
          dfs(dep+1,a[dep],1,qj);
          dfs(dep+1,-1,0,qj);
        }
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    bool allone=1;
    bool allunderone=1;
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]!=1){
            allone=0;
        }
        if(a[i]>1){
            allunderone=0;
        }
    }
    if(allone&&n>10&&k==0){
        printf("%lld",n/2);
        return 0;
    }
    if(allunderone){
        if(k==1){
            //bu hui pian fen
        }
    }
    dfs(1,-1,0,0);
    printf("%lld",ans);
    return 0;
}
//rp++
