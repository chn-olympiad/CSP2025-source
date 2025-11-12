#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
const ll M = 1e9 + 7, B = 1049, NN = 1e6 + 10, N = 2e5 + 10;
map <pii,int> mp;
int n,q;
ll pw[NN],inv[NN];
ll hss[N],hst[N];
set <int> len;
ll qpow(ll x,ll p){
    ll ans = 1;
    while(p){
        if(p & 1) ans = x * ans % M;
        x = x * x % M;
        p >>= 1;
    }
    return ans % M;
}
void init(){
    pw[0] = 1;
    int maxn = 1e6;
    for(int i=1;i<=maxn;i++){
        pw[i] = B * pw[i - 1] % M;
    }
    inv[maxn] = qpow(pw[maxn],M - 2);
    for(int i=maxn-1;i>=1;i--){
        inv[i] = inv[i + 1] * B % M;
    }
}
int geth(string s){
    ll ans = 0;
    for(int i=0;i<s.size();i++){
        ll p = s[i] - 'a';
        ans = (ans + pw[i] * p % M) % M; 
    }
    return ans % M;
}
ll calcs(int i,int j){
    i ++; j ++;
    if(i > j) return 0;
    return (hss[j] - hss[i - 1] + M) % M;
}
ll calct(int i,int j){
	if(i > j) return 0;
    i ++; j ++;
    return (hst[j] - hst[i - 1] + M) % M;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>q;
    init();
    string s,t;

    // cin>>s;
    // for(int i=0;i<s.size();i++){
    //     ll p = s[i] - 'a';
    //     hss[i + 1] = 0;
    //     hss[i + 1] = (hss[i] + pw[i + 1] * p % M) % M; 
    // }
    // for(int i=1;i<=s.size();i++){
    // 	cout<<hss[i]<<" ";
	// }
	// cout<<"\n";
    // for(int i=0;i<s.size();i++){
    //     for(int j=0;j<=i;j++){
    //         string res = s.substr(j,i-j+1);
    //         if(geth(res) != calcs(j,i) * inv[j + 1] % M){
    //         	cout<<j<<" "<<i<<" "<<geth(res)<<" "<<calcs(j,i) * inv[j + 1] % M<<"\n";
	// 		}
    //     }
    // }
    for(int i=1;i<=n;i++){
        cin>>s>>t;
        //len.insert(s.size());
        int p = geth(s), q = geth(t);
        //cout<<p<<" "<<q<<"\n";
        mp[make_pair(p,q)] ++;
    }
    //cout<<"fdsfd\n";
    while(q--){
        cin>>s>>t;
        if(s.size() != t.size()){
            cout<<"0\n";
            continue;
        }
        for(int i=0;i<s.size();i++){
            ll p = s[i] - 'a';
            hss[i + 1] = 0;
            hss[i + 1] = (hss[i] + pw[i + 1] * p % M) % M; 
        }
        for(int i=0;i<t.size();i++){
            ll p = t[i] - 'a';
            hst[i + 1] = 0;
            hst[i + 1] = (hst[i] + pw[i + 1] * p % M) % M; 
        }
        int pos = 0; bool f = 0;
        ll ans = 0;
        for(int i=0;i<s.size();i++){
            if(f == 0 && calcs(0,i) == calct(0,i)){
                pos = i;
            }
            else{
            	f = 1;
			}
            if(calcs(i+1,s.size()-1) == calct(i+1,s.size()-1)){
                for(int j=0;j<=pos+1;j++){
                	//cout<<i<<" "<<j<<"\n";
                    ll res1 = calcs(j,i) * inv[j + 1] % M;
                    ll res2 = calct(j,i) * inv[j + 1] % M;
                    //ll res1 = geth(s.substr(j,i-j+1));
                    //ll res2 = geth(t.substr(j,i-j+1));
                    //cout<<s.substr(j,i-j+1)<<" "<<geth("xabcx")<<" st \n";
                    //cout<<res1<<" "<<res2<<" res\n";
                    auto pi = make_pair(res1,res2);
                    if(mp.count(pi)) ans += mp[pi];
                    //cout<<ans<<"\n";
                }
            }
        }
//        int i = n;
//                for(int j=0;j<=pos+1;j++){
//                	//cout<<i<<" "<<j<<"\n";
//                    ll res1 = calcs(j,i) * inv[j + 1] % M;
//                    ll res2 = calct(j,i) * inv[j + 1] % M;
//                    //ll res1 = geth(s.substr(j,i-j+1));
//                    //ll res2 = geth(t.substr(j,i-j+1));
//                    //cout<<s.substr(j,i-j+1)<<" "<<geth("xabcx")<<" st \n";
//                    //cout<<res1<<" "<<res2<<" res\n";
//                    auto pi = make_pair(res1,res2);
//                    if(mp.count(pi)) ans += mp[pi];
//                    //cout<<ans<<"\n";
//                }
        //cout<<pos<<" ";
        cout<<ans<<"\n";
    }


    return 0;
}
