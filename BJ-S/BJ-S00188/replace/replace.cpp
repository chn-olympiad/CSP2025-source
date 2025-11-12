#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define MAXL 5000005
#define P 13331
int st[MAXN],siz[MAXN];
unsigned long long hasher1[MAXN],hasher2[MAXN];
vector<int> diflen[MAXL];
unsigned long long hasher3[MAXL],hasher4[MAXL];
unsigned long long mul[MAXL];
unsigned long long diffhash1[MAXN],diffhash2[MAXN];
unsigned long long cal(int x,int y,int opt){
    if(opt == 1){
        return hasher3[y] - hasher3[x-1] * mul[y-x+1];
    }else return hasher4[y] - hasher4[x-1] * mul[y-x+1];
}
unordered_map<unsigned long long,int> mp;
vector<int> differ_ha[MAXN];
unsigned long long jiehou(unsigned long long a1,unsigned long long a2){
    return a1 * P + a2 * P * P * 133;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    mul[0] = 1;
    for(int i = 1; i <= 5000000; i++) mul[i] = mul[i-1] * P;
    int n,q; scanf("%d%d",&n,&q);
    for(int i = 1; i <= n; i++){
        string s1,s2; cin >> s1 >> s2;
        int m = s1.size();
        siz[i] = m;
        int st1 = -1,ed = -2;
        for(int j = 0; j < m; j++){
            if(s1[j] != s2[j]){
                st1 = j; break;
            }
        }
        for(int j = m-1; j >= 0; j--){
            if(s1[j] != s2[j]){
                ed = j; break;
            }
        }
        diflen[ed - st1 + 1].push_back(i);
        st[i] = st1;
        for(int j = 0; j < m; j++) hasher1[i] = hasher1[i] * P + s1[j];
        for(int j = 0; j < m; j++) hasher2[i] = hasher2[i] * P + s2[j];
        for(int j = st1; j <= ed; j++) diffhash1[i] = diffhash1[i] * P + (s1[j]);
        for(int j = st1; j <= ed; j++) diffhash2[i] = diffhash2[i] * P + (s2[j]);
        unsigned long long lst = jiehou(diffhash1[i],diffhash2[i]);
        if(mp[lst] == 0) mp[lst] = i;
        differ_ha[mp[lst]].push_back(i);
    
    }
    while(q--){
        string s1,s2; cin >> s1 >> s2;
        int m = s1.size();
        int stt = -1,ed = -2;
        for(int j = 0; j < m; j++){
            if(s1[j] != s2[j]){
                stt = j; break;
            }
        }
        for(int j = m-1; j >= 0; j--){
            if(s1[j] != s2[j]){
                ed = j; break;
            }
        }
        long long ans = 0;
        hasher3[0] = s1[0];
        hasher4[0] = s2[0];
        for(int j = 1; j < m; j++) hasher3[j] = hasher3[j-1] * P + s1[j];
        for(int j = 1; j < m; j++) hasher4[j] = hasher4[j-1] * P + s2[j];
        unsigned long long ciquan = jiehou(cal(stt,ed,1),cal(stt,ed,2));
        int tmp = mp[ciquan];
        if(tmp == 0){printf("0\n"); continue;}
        for(int v : differ_ha[tmp]){
            if(stt - st[v] < 0 || stt - st[v] + siz[v] > m) continue;
            if(cal(stt - st[v],stt - st[v] + siz[v] - 1,1) == hasher1[v] && 
               cal(stt - st[v],stt - st[v] + siz[v] - 1,2) == hasher2[v]) ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}