#include<bits/stdc++.h>
typedef long long ll;
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define mem0(s) memset(s,0,sizeof(s))
#define memf(s) memset(s,0x7f,sizeof(s))
using namespace std;
const int N = 1e6+10;
const ll M = 1e9+10;
ll n,m,k,cnt;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&m); 
	f(i,1,n){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	f(k,1,m){
		string s,s1;
		cin>>s>>s1;
		if(s.size()!=s1.size()){
			cout<<0<<endl;
			continue;
		}
		ll cnt=0;
		f(i,0,s.size()-1){
			f(j,i,s.size()-1){
				ll len=j-i+1;
				ll len1=s.size()-j-1;
				if(i&&s.substr(0,i)!=s1.substr(0,i)) continue;
				if(j<s.size()-1&&s.substr(j+1,len1)!=s1.substr(j+1,len1)) continue;
				if(mp[s.substr(i,len)]==s1.substr(i,len)) cnt++;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}

