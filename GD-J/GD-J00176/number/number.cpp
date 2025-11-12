#include<bits/stdc++.h>
typedef long long ll;
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define mem0(p) memset(p,0,sizeof(p))
#define memf(p) memset(p,0x7f,sizeof(p))
#define fs first
#define sc second
#define pb push_back
using namespace std;
const int N = 1e5 + 10;
const ll M = 1e9+10;
string s;
vector<ll> vec;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	f(i,0,s.size()-1){
		if(s[i]>='0'&&s[i]<='9'){
			vec.pb(s[i]-'0');
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	for(auto t:vec){
		printf("%lld",t);
	}
	return 0; 
}
