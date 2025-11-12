//GZ-S00100   遵义市第四中学   周俊翰 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct play{
	ll a,b,c,p;
}; play m[100004];
ll n,t,ans=0;
void dfs(ll a,ll b,ll c,ll o,ll k){
	if(a>n/2||b>n/2||c>n/2){
		return;
	}
	if(k==n&&o>ans){
		ans=o;
	}
	dfs(a+1,b,c,o+m[k].a,k+1);
	dfs(a,b+1,c,o+m[k].b,k+1);
	dfs(a,b,c+1,o+m[k].c,k+1);
}
bool cmp1(play x,play y){
	if(x.a>y.a){
		return 1;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(ll q=0;q<t;q++){
		ans=0;
		scanf("%lld",&n);
		for(ll j=0;j<n;j++){
			scanf("%lld%lld%lld",&m[j].a,&m[j].b,&m[j].c);
		}
		int temp=0;
		for(int j=0;j<n;j++){
			if(m[j].b!=0||m[j].c!=0) break;
			temp=1;
		}
		for(int j=0;j<n;j++){
			if(m[j].c!=0) break;
			temp=2;
		}
		if(temp==1){
			sort(m,m+n,cmp1);
			for(int j=0;j<n/2;j++){
				ans+=m[j].a;
			}
			printf("%lld\n",ans);
			continue;
		}
		if(temp==2){
			sort(m,m+n,cmp1);
			int anum=0,i=0;
			int n1=n/2;
			while(anum<n1&&i<n){
				if((m[i].a>m[i].b)&&(m[i].a>m[i].c)){
					ans+=m[i].a;
					m[i].p=1;
					anum++;
				}
				i++;
			}
			for(int i=0;i<n;i++){
				if(m[i].p==1) ans+=m[i].b;
			}
			printf("%lld\n",ans);
			continue;
		}
		dfs(0,0,0,0,0);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

