#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 214514;
int _,n,m,k,t,a[N],b[N],ans,cnt,tot;
string s;
bool vis[N],f;
map<int, int> mp;
struct mb{
	int x;
	int y;
}p[N];
bool cmp(mb l,mb r){
	if(l.y==r.y){
		return l.x>r.x;
	}
	return l.y<r.y;
}
void solve(){
	b[0]=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=(b[i-1]^a[i]);
		if(mp[(b[i]^m)]!=0||b[i]==m){
			p[++tot].x=mp[(b[i]^m)]+1;
			p[tot].y=i;
		}
		mp[b[i]]=i;
	}
	sort(p+1,p+tot+1,cmp);
	int l=0;
	for(int i=1;i<=tot;i++){
		if(p[i].x>l){
			ans++;
			l=p[i].y;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	_=1;
	while(_--){
		solve();
	}
}
