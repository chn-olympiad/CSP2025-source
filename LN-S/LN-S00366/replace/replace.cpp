#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int mod = 130266161;
char s[3][5000005];
char t[3][5000005];
int us[200005];
int cnt[3];
int L,R;
struct cg{
    long long s1,s2; int len;
    friend bool operator < (cg a,cg b){
        if(a.len != b.len)return a.len < b.len;
        if(a.s1 != b.s1)return a.s1 < b.s1; return a.s2 < b.s2;
    }
}z,k,c[200005];
struct node{vector <char> tr[3];};
node mp[200005];
cg fd(int len){
    L = 1; R = len; cg ans = z;
    while(s[1][L] == s[2][L] && L <= len)L++;
    while(s[1][R] == s[2][R] && R >= 1)R--;
    ans.len = R-L+1; if(!ans.len)return z;
    for(int i = L;i <= R;i++){
        ans.s1 = (ans.s1*67 + s[1][i]-'a')%mod;
        ans.s2 = (ans.s2*67 + s[2][i]-'a')%mod;
    }
    return ans;
}
void nt(){
    int len = strlen(s[1]+1); k = fd(len);
    if(!k.len)return; cnt[1] = L-1; cnt[2] = len-R;
    for(int i = L-1;i >= 1;i--)t[1][L-i] = s[1][i];
    for(int i = R+1;i <= len;i++)t[2][i-R] = s[1][i];
    return;
}
void ist(node& T){
    for(int i = 1;i <= 2;i++)
        for(int j = 1;j <= cnt[i];j++)T.tr[i].push_back(t[i][j]);
    return;
}
bool jg(cg a,cg b){return (a.len == b.len)&(a.s1 == b.s1)&(a.s2 == b.s2);}
bool ck(int i){
    for(int p = 1;p <= 2;p++){
        if(cnt[p] < mp[i].tr[p].size())return 0;
        for(int j = 0;j < mp[i].tr[p].size();j++)
            if(t[p][j+1] != mp[i].tr[p][j])return 0;
    }
    return 1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q; scanf("%d%d",&n,&q);
    for(int i = 1;i <= n;i++){
        scanf("%s",s[1]+1); scanf("%s",s[2]+1);
        nt(); c[i] = k; if(!k.len)continue;
        ist(mp[i]);
    }
    for(int i = 1;i <= q;i++){
        scanf("%s",s[1]+1); scanf("%s",s[2]+1);
        nt(); int ans = 0;
        for(int j = 1;j <= n;j++)
            {if(!jg(c[j],k))continue; ans+= ck(j);}
        printf("%d\n",ans);
    }
    return 0;
}