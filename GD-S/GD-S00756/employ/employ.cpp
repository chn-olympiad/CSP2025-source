#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=520,p=998244353;
ll ans,A[N];
char s[N];
int n,cnt1,m,c[N],a[N],mt[N];
bool vis[N];
inline void init(){
	ll res=1;
	A[0]=1;
	for(int i=1;i<=500;i++){
		res=(res*i)%p;
		A[i]=res;
	}
}
bool pA=1;
void dfs(int x){
	if(a[x]==a[x-1]) return;
	if(x>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]>mt[i]) cnt++;
			if(cnt>=m){
				ans++;
				return;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		a[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	a[0]=10086;
	cin>>n>>m>>s+1;
	init();
	for(int i=1;i<=n;i++){
		if(s[i]!='1'){
			pA=0;
			mt[i+1]++;
		}
		mt[i]+=mt[i-1];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
		if(!c[i]) cnt1++;
	}
	if(pA){
		cout<<A[n-cnt1+1];
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
//这题好难，骗不了一点 
