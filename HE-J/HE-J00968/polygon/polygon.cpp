#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5050;
const ll MOD=998244353;
ll n,a[MAXN],ans,jian,cnt;
void dfs1(ll length,ll maxlen,ll step){
	if(cnt>=3&&length>maxlen*2){
		ans++;
//		printf("length:%i,cnt:%i,maxlen:%i\n",length,cnt,maxlen);
	}
	if(step>n)return;
	cnt++;
	dfs1(length+a[step],max(maxlen,a[step]),step+1);
	cnt--;
	dfs1(length,maxlen,step+1);
}
void dfs2(ll length,ll maxlen,ll step){
	if(cnt>=3&&length>maxlen*2){
		jian++;
//		printf("length:%i,cnt:%i,maxlen:%i\n",length,cnt,maxlen);
	}
	if(step>=n)return;
	cnt++;
	dfs2(length+a[step],max(maxlen,a[step]),step+1);
	cnt--;
	dfs2(length,maxlen,step+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ll maxa=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(maxa==1){
		cout<<((n-1)%MOD*(n-2)%MOD)%MOD/2;
	}
	else{
		dfs1(0,0,1);
		dfs2(0,0,1);
		cout<<ans%MOD-(jian%MOD);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//5 1 2 3 4 5
