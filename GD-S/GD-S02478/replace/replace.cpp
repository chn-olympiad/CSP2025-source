#include<iostream>
#include<cstring>
#include<map>
#define ll long long
using namespace std;

const int mod=1e9+7;
const int base=131;
int n, q;
ll sum=0;
ll h[500010], hh[500010];
ll ha[5000010], haa[5000010];
ll pos[5000010];
ll c[200010], cc[200010];
char s[500010], ss[500010];

int main(){
	
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		cin >> s >> ss;
		c[i]=strlen(s); cc[i]=strlen(ss);
		h[i]=hh[i]=1;
		for(int j=0; j<c[i]; j++){
			h[i]=(h[i]*base+s[j]-'a'+1)%mod;
		}
		for(int j=0; j<cc[i]; j++){
			hh[i]=(hh[i]*base+ss[j]-'a'+1)%mod;
		}
	}
	pos[0]=1;
	for(int i=1; i<=5000000; i++){
		pos[i]=(pos[i-1]*base)%mod;
	}
	while(q--){
		cin >> s >> ss;
		int len1=strlen(s), len2=strlen(ss);
		ha[0]=haa[0]=1;
		for(int i=1; i<=len1; i++){
			ha[i]=(ha[i-1]*base+s[i-1]-'a'+1)%mod;
		}
		for(int i=1; i<=len2; i++){
			haa[i]=(haa[i-1]*base+ss[i-1]-'a'+1)%mod;
		}
		ll ans=0;
		ha[0]=0;
		for(int i=1; i<=len1; i++){
			for(int j=1; j<=n; j++){
				if(ha[i+c[j]-1]-ha[i-1]==(h[j]*pos[i-1])%mod){
					if((ha[i-1]+(hh[j]*pos[i-1])%mod+ha[len1]-ha[i+cc[j]+1])%mod==haa[len2]){
						ans++;
					}	
				}
			}
		}
		cout << ans << '\n'; 
	}
	
	return 0;
}
