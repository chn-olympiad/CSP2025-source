#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=1e6+10;
const ll mod=998244353;
ll n,m,a[inf],aa[inf],tot,ans;
string s;
char ch[inf];
bool cmp(int a,int b){ return a<b; };
void bfs(int day){
	if(day==n+1){
		ans++;
		ans%=mod;
		return ;
	}
	if(ch[day]==0) bfs(day+1);
	if(ch[day]==1){
		a[++tot]=0;
		bfs(day+1);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",&s);
	for(ll i=1;i<=n;i++) ch[i]=s[i-1],aa[i]=aa[i-1]+ch[i]-'0';
	for(ll i=1;i<=m;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+m,cmp);
	bfs(1);
	cout<<ans<<endl;
	return 0;
}
