#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define pii pair<int,int>
#define fi first
#define mp make_pair
#define se second
#define gc getchar()
#define pb push_back
using namespace std;
int T,n;
const int N=100099;
void rd(int &x){
	char c=gc;
	x=0;
	int f=1;
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=gc;
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=gc;
	}
	x*=f;
	return ;
}
struct stu{
	vector<pii>a;
}s[N];
vector<int>she[3];
int ans=0;
vector<int>kui;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	rd(T);
	while(T--){
		ans=0;
		kui.clear();
		FOR(j,0,3)she[j].clear();
		rd(n);
		FOR(i,1,n){
			s[i].a.clear();	
			FOR(j,0,2){
				int val;
				rd(val);
				s[i].a.pb(mp(val,j));
			}
			sort(s[i].a.begin(),s[i].a.end());
			she[s[i].a[2].se].pb(i);
			ans+=s[i].a[2].fi;
		}
		int mas=0;
		FOR(j,1,2)if(she[j].size()>she[mas].size())mas=j;
		if((int)she[mas].size()<=n/2){
			printf("%d\n",ans);
			continue;
		}
		FOR(i,1,n)if(s[i].a[2].se==mas)kui.pb(s[i].a[2].fi-s[i].a[1].fi);
		sort(kui.begin(),kui.end());
		int dao=she[mas].size()-n/2;
		FOR(j,0,dao-1){
			ans-=kui[j];
		}
		printf("%d\n",ans);
	}
	return 0;
}
//dzy happy every day!
//dzy PhO rp++!