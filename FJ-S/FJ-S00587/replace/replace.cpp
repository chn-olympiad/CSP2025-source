#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2145145;
int _,n,m,k,t,a[N],b[N],ans,cnt,tot,op[N];
bool f,vis[N];
struct mb{
	string x,y;
	int l,w;
}s[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].x>>s[i].y;
		s[i].l=s[i].x.length();
		for(int j=0;j<s[i].l;j++){
			if(s[i].x[j]!=s[i].y[j]){
				s[i].w=j;
				break;
			}
		}
	}
	while(m--){
		ans=0;
		string o,p;
		cin>>o>>p;
		int uu,oo;
		int ll=o.length();
		int jo=p.length();
		if(ll!=jo){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<ll;i++){
			if(o[i]!=p[i]){
				uu=i;
				break;
			}
		}
		for(int i=o.length()-1;i>=0;i--){
			if(o[i]!=p[i]){
				oo=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i].w<=uu){
				string aa=o.substr(uu-s[i].w,s[i].l);
				string bb=p.substr(uu-s[i].w,s[i].l);
				if(aa==s[i].x&&bb==s[i].y&&uu-s[i].w+s[i].l-1>=oo){
					ans++; 
				}
			}
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	_=1;
	while(_--){
		solve();
	}
	return 0; 
}
