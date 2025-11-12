#include<iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=505;
const ll MOD=998244353;

int n,m,a[N],c[N];
bool vis[N];
string s;
ll ans;

ll f(int x){
	ll ret=1;
	for(int i=x;i>=1;i--){
		ret=ret%MOD*i%MOD;
	}
	return ret;
}

void dfs(int t){
	if(t>n){
		int p=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0') p++;
			else{
				if(p>=c[a[i]]) p++;
				else cnt++;
			}
		} 
		if(cnt>=m){
			ans++;
			ans%=MOD;
		}
		return;
	} 
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		a[t]=i;
		dfs(t+1);
		vis[i]=0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0) t++;
	}
	bool zero=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			zero=1;
			break;
		}
	}
	if(!zero){
		cout<<f(t)<<endl;
	}else if(n<=10){
		dfs(1);
		cout<<ans<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
}

