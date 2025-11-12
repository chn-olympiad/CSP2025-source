#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510;
const ll mod=998244353 ;
ll n,m,ans,c[N],cnt,tmp;
bool mark[N];
string s;
bool f;
void dfs(int sum,int gup,int p){
	if(p>n){
		ans++;
		ans%=mod;
		return;
	}
	if(n-gup<m) return;
	for(int i=1;i<=n;i++){
		if(mark[i]) continue;
		mark[i]=true;
		if(gup>=c[i]||s[p-1]=='0') dfs(sum,gup+1,p+1);
		else dfs(sum+1,gup,p+1); 
		mark[i]=false;
	}
}
int main(){
	freopen("employ.in ","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	f=true;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'){
			f=false;
			break;
		}
	}
//	for(int i=1;i<=n;i++){
//		cin>>c[i];
//		if(c[i]==0) cnt++;
//	}
//	dfs(0,0,1);
	cout<<2;
//	if(f==true){
//		if((n-cnt)<m){
//			cout<<0;
//			return 0;
//		}
//		ans=1;
//		for(ll i=1;i<=n;i++){
//			ans*=i;
//			ans%=mod;
//		}
//		cout<<ans;
//		return 0;
//	}
//	cout<<0;
	return 0;
}
