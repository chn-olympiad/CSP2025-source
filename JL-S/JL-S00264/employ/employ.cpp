#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=998244353;

ll qpow(ll a,ll b){
	ll res=1;
	for (;b;b>>=1,a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

int n,m;
string s;
int c[501],p[501];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s='_'+s;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=n;i++) p[i]=i;
    int ans=0;
    do{
        int cnt0=0,cnt1=0;
        for (int i=1;i<=n;i++){
            if (cnt0>=c[p[i]] or s[i]=='0') cnt0++;
            else{
                if ((++cnt1)>=m){
                    ans++;
                    break;
                }
            }
        }
    }while (next_permutation(p+1,p+n+1));
    cout<<ans;
	return 0;
}