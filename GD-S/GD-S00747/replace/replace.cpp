#include<cstdio>
#include<queue>
#include<vector>
#include<unordered_map>
const int N=5e6+1, P1=131, M=998244353, P2=137, NN=2e5+1;
int n, m, slen[N], len1=0, len2=0;
long long hash1[N], hash2[N], Hash1=0, Hash2=0;
long long pw1[N], pw2[N], tmphash1, tmphash2;
long long shash1[NN], shash2[NN];
unsigned long long hashpair[N];
std::unordered_map<unsigned long long, int> mp;
struct ACAM {
    int tree[N][26], tot;
    int fail[N], t[N];
    std::vector<int> e[N];
    void insert(char* s, int id) {
        int now=0;
        for(int i=0; s[i]; i++) {
            if(!tree[now][s[i]-'a']) tree[now][s[i]-'a']=++tot;
            now=tree[now][s[i]-'a'];
            t[now]=s[i]-'a';
        }
        e[now].emplace_back(id);
    }
    void build() {
        int now=0;
        std::queue<std::pair<int, int>> q;
        q.emplace(0, 0);
        while(!q.empty()) {
            int u=q.front().first, fa=q.front().second;
            q.pop();
            while(fa&&!tree[fa][t[u]]) fa=fail[fa];
            if(u&&tree[fa][t[u]]&&u!=tree[fa][t[u]]) fail[u]=tree[fa][t[u]];
            else fail[u]=fa;
            for(int i=0; i<26; i++) {
                if(tree[u][i]) q.emplace(tree[u][i], fail[u]);
            }
        }
    }
    bool calc(int pos, int j, int len) {
        pos++;
        long long tmp1=hash1[pos-len], tmp3=(hash1[len1]-hash1[pos]*pw1[len1-pos]%M+M)%M;
        long long tmp11=hash2[pos-len], tmp31=(hash2[len1]-hash2[pos]*pw2[len1-pos]%M+M)%M;
        if(Hash1==(tmp1*pw1[len1-(pos-len)]%M+shash1[j]*pw1[len1-pos]%M+tmp3)%M&&Hash2==(tmp11*pw2[len1-(pos-len)]%M+shash2[j]*pw2[len1-pos]%M+tmp31)) return true;
        return false;
    }
    int kmp(char *s) {
        int j=0, ans=0;
        for(int i=0; s[i]; i++) {
            while(j&&!tree[j][s[i]-'a']) j=fail[j];
            if(tree[j][s[i]-'a']) j=tree[j][s[i]-'a'];
            if(!e[j].empty()) {
                for(int k:e[j]) {
                    if(calc(i, k, slen[k])) ans+=mp[hashpair[k]];
                }
            }
            int f=fail[j];
            while(f) {
                for(int k:e[f]) {
                    if(calc(i, k, slen[k])) ans+=mp[hashpair[k]];
                }
                f=fail[f];
            }
        }
        return ans;
    }
}ac;
char s[N], t[N];
unsigned long long work(unsigned long long a, unsigned long long b) {
    return (a*0x19630282513llu)^(a>>15)+b+(b<<17)*0x1271641345llu;
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    pw1[0]=pw2[0]=1;
    for(int i=1; i<N; i++) {
        pw1[i]=pw1[i-1]*P1%M;
        pw2[i]=pw2[i-1]*P2%M;
    }
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%s %s", s+1, t+1);
        tmphash1=0;
        for(int j=1; s[j]; j++) tmphash1=(tmphash1*P1+s[j])%M;
        for(int j=1; t[j]; j++) shash1[i]=(shash1[i]*P1+t[j])%M, shash2[i]=(shash2[i]*P2+t[j])%M, slen[i]++;
        unsigned long long now=work(tmphash1, shash1[i]);
        if(!mp[now]) ac.insert(s+1, i);
        mp[now]++;
        hashpair[i]=now;
    }
    ac.build();
    while(m--) {
        scanf("%s %s", s+1, t+1);
        Hash1=Hash2=len1=len2=0;
        for(int i=1; s[i]; i++) {
            hash1[i]=(hash1[i-1]*P1+s[i])%M;
            hash2[i]=(hash2[i-1]*P2+s[i])%M;
            len1++;
        }
        for(int i=1; t[i]; i++) {
            Hash1=(Hash1*P1+t[i])%M;
            Hash2=(Hash2*P2+t[i])%M;
            len2++;
        }
        if(len1!=len2) {
            printf("0\n");
            continue;
        }
        printf("%d\n", ac.kmp(s+1));
    }
}