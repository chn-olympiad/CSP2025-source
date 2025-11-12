#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll t,n,ans,cnt,f[5];
struct stu{
	ll a1,a2,a3,id;
}d[N];
void dfs(ll j,ll num,ll b1,ll b2,ll b3){
	if(j==n+1){
		ans=max(ans,num);
		return ;
	}
	if(b1<n/2) dfs(j+1,num+d[j].a1,b1+1,b2,b3);
	if(b2<n/2) dfs(j+1,num+d[j].a2,b1,b2+1,b3);
	if(b3<n/2) dfs(j+1,num+d[j].a3,b1,b2,b3+1);
}
ll rd(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	cin>>t;
	t=rd();
	while(t--){
//		cin>>n;
		n=rd();
		ans=cnt=0;
		for(ll i=1;i<=n;i++){
//			cin>>d[i].a1>>d[i].a2>>d[i].a3;
			d[i].a1=rd();d[i].a2=rd();d[i].a3=rd();
			d[i].id=i;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
