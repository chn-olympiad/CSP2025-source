#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,p[3],ans,f[100010][3];
struct Node{
	int a[3];
}s[100010];
void fun(ll x,ll a,ll b,ll c,ll sum,ll k){
	if(x==n+1){
		ans=max(ans,sum);
	}
	if(a<k)fun(x+1,a+1,b,c,sum+s[x].a[0],k);
	if(b<k)fun(x+1,a,b+1,c,sum+s[x].a[1],k);
	if(c<k)fun(x+1,a,b,c+1,sum+s[x].a[2],k);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		int k= n/2;
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;++i){
			cin>>s[i].a[0]>>s[i].a[1]>>s[i].a[2];
		}
		fun(1,0,0,0,0,n/2);
		cout<<ans<<'\n';
	}
	return 0;
}
