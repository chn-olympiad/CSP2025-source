#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
typedef pair<ll,ll> P;
const ll N = 2e5+15,mod = 1e8+7;
ll read(){
    ll a = 1,ans = 0;
    char x = getchar();
    while(x < '0'||x > '9'){if(x=='-')a=-1;x=getchar();}
    while(x >= '0'&&x <= '9')ans = ans*10+x-'0',x = getchar();
    return ans*a;
}
char tmp1[N],tmp2[N];
ll mul[5000005];
void init(){
    mul[0] = 1;
    for(int i = 1;i <= 5000000;i ++)
        mul[i] = mul[i-1]*127%mod;
}
map<ll,ll> mp;
map<ll,ll> pre[N],suf[N];
vector<ll> num[N*2];
ll difcnt = 0,pcnt = 0;
bool yon[N];
void work(){
    ll n = read(),q = read();
    for(int i = 1;i <= n;i ++){
        scanf("%s%s",tmp1+1,tmp2+1);
        ll m = strlen(tmp1+1);
        ll st = 0,ed = 0;
        for(int j = 1;j <= m;j ++){
            if(tmp1[j] != tmp2[j]){
                if(!st)st = j;
                ed = j;
            }
        }
        if(st == 0)continue;
        ll hsh = 0;
        for(int j = st;j <= ed;j ++){
            hsh = hsh*127+tmp1[j];
            hsh = hsh*127+tmp2[j];
            hsh %= mod;
        }
        ll Pre = 0,End = 0;
        for(int j = st-1;j >= 1;j --){
            Pre = (Pre*127+tmp1[j])%mod;
        }
        for(int j = ed+1;j <= m;j ++){
            End = (End*127+tmp1[j])%mod;
        }
//        cout<<hsh<<" "<<Pre<<" "<<End<<endl;
        if(mp.count(hsh)){
            if(pre[mp[hsh]].count(Pre))num[pre[mp[hsh]][Pre]].push_back(i);
            else num[++pcnt].push_back(i),pre[mp[hsh]][Pre] = pcnt;
            if(suf[mp[hsh]].count(End))num[suf[mp[hsh]][End]].push_back(i);
            else num[++pcnt].push_back(i),suf[mp[hsh]][End] = pcnt;
        }else{
            mp[hsh] = ++difcnt;
            pre[difcnt][Pre] = ++pcnt;num[pcnt].push_back(i);
            suf[difcnt][End] = ++pcnt;num[pcnt].push_back(i);
        }
    }
//    for(int i = 1;i <= pcnt;i ++,cout<<endl)
//    for(int j = 0;j < num[i].size();j++)cout<<num[i][j]<<" ";
    while(q --){
        scanf("%s%s",tmp1+1,tmp2+1);
        ll m = strlen(tmp1+1);
        ll st = 0,ed = 0;
        for(int j = 1;j <= m;j ++){
            if(tmp1[j] != tmp2[j]){
                if(!st)st = j;
                ed = j;
            }
        }
        ll hsh = 0;
        for(int j = st;j <= ed;j ++){
            hsh = hsh*127+tmp1[j];
            hsh = hsh*127+tmp2[j];
            hsh %= mod;
        }
        if(!mp[hsh]){
            printf("0\n");
            continue;
        }
        ll ans = 0;
        ll Pre = 0,End = 0;
		if(pre[mp[hsh]][0]){
			ll k = pre[mp[hsh]][0];
			for(int i = 0;i < num[k].size();i ++)yon[num[k][i]] = 1;
		}
        for(int j = st-1;j >= 1;j --){
            Pre = (Pre*127+tmp1[j])%mod;
            if(pre[mp[hsh]][Pre]){
                ll k = pre[mp[hsh]][Pre];
                for(int i = 0;i < num[k].size();i ++)yon[num[k][i]] = 1;
            }
        }
		if(suf[mp[hsh]][0]){
			ll k = suf[mp[hsh]][0];
			for(int i = 0;i < num[k].size();i ++)ans += yon[num[k][i]];
		}
        for(int j = ed+1;j <= m;j ++){
            End = (End*127+tmp1[j])%mod;
            if(suf[mp[hsh]][End]){
                ll k = suf[mp[hsh]][End];
                for(int i = 0;i < num[k].size();i ++)ans += yon[num[k][i]];
            }
        }
        Pre = 0;
		if(pre[mp[hsh]][0]){
			ll k = pre[mp[hsh]][0];
			for(int i = 0;i < num[k].size();i ++)yon[num[k][i]] = 0;
		}
        for(int j = st-1;j >= 1;j --){
            Pre = (Pre*127+tmp1[j])%mod;
            if(pre[mp[hsh]][Pre]){
                ll k = pre[mp[hsh]][Pre];
                for(int i = 0;i < num[k].size();i ++)yon[num[k][i]] = 0;
            }
        }
        printf("%lld\n",ans);
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ll T = 1;
    while(T--)work();
    return 0;
}
/*
3 1
aba aca
aaa bbb
aaaba aaaca
aaabaa aaacaa
*/
