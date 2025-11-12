#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5,M=25e5;
ll n,k,a[N],ans,t[M];
queue<ll>q;
//===================================================================
void Back_to_Clear(){
	while(!q.empty()){
		ll now=q.front();
		t[now]=0;
		q.pop();
	}
}
//===================================================================
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll now=0; t[0]=1;
	for(int i=1;i<=n;i++){
		now=(now^a[i]);
		if(t[(k^now)]){
			++ans; now=0;
			Back_to_Clear();
			t[0]=1;
		}else{
			++t[now];
			q.push(now);
		}
	}cout<<ans;
	return 0;
}
