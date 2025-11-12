#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define pi pair<int,int>
#define arr(a) array<int,(a)>
#define cases(_) while((_)--) solve()
#define RE return puts("0"),void();
using namespace std;
const int N=0;
int _=1,n,sum,a,b,c;
vector<int> v[3];
void solve(){
	scanf("%d",&n),sum=0;
	rep(o,0,2) v[o].clear();
	rep(i,1,n){
		scanf("%d%d%d",&a,&b,&c);
		int mx=max(a,max(b,c));
		if(mx==a) sum+=a,v[0].push_back(min(a-b,a-c));
		else if(mx==b) sum+=b,v[1].push_back(min(b-a,b-c));
		else if(mx==c) sum+=c,v[2].push_back(min(c-a,c-b));
	}
	rep(o,0,2) if((int)v[o].size()>n/2){
		sort(v[o].begin(),v[o].end());
		int k=(int)v[o].size()-n/2;
		rep(i,0,k-1) sum-=v[o][i];
	}
	printf("%d\n",sum);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&_);
	cases(_);
	return 0;
}
