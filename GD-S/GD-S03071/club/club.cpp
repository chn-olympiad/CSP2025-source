#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,a[100005],b[1000005],c[100005],maxx;
void dfs(ll x,ll aa,ll bb,ll cc,ll cnt){
	if(x==n+1){
		maxx=max(maxx,cnt);
		return;
	}
	if(aa) dfs(x+1,aa-1,bb,cc,cnt+a[x]);
	if(bb) dfs(x+1,aa,bb-1,cc,cnt+b[x]);
	if(cc) dfs(x+1,aa,bb,cc-1,cnt+c[x]);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n,maxx=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			maxx=max(maxx,max(b[i],c[i]));
		}
		if(!maxx){
			sort(a+1,a+n+1);
			ll cnt=0;
			for(int i=1;i<=n/2;i++)
				cnt+=a[i];
			cout<<cnt<<"\n";
		}
		else{
			maxx=0;
			dfs(1,n/2,n/2,n/2,0);
			cout<<maxx<<"\n";
		}
	}

	return 0;
}

