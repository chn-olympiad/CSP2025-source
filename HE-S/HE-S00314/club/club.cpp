#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MN=1e5+115;
struct Node{
	int a, b, c;
	bool operator <(const Node &o)const{
		return max(max(a,b),c)>max(max(o.a,o.b),o.c);
	}
}tmp[MN];
int n, a[MN], b[MN], c[MN], ans=0;
int maxn[MN], secmaxn[MN];
int maxnid[MN], secid[MN];
void Read(){
	cin>>n; ans=0;
	for(int i=1; i<=n; ++i) cin>>tmp[i].a>>tmp[i].b>>tmp[i].c;
	sort(tmp+1,tmp+n+1);
	for(int i=1; i<=n; ++i) a[i]=tmp[i].a;
	for(int i=1; i<=n; ++i) b[i]=tmp[i].b;
	for(int i=1; i<=n; ++i) c[i]=tmp[i].c;
	//for(int i=1; i<=n; ++i) cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<'\n';
}
priority_queue <pair<int,int> > q1, q2, q3;
void Solve(){
	Read();
	for(int i=1; i<=n; ++i){
		maxn[i]=max(max(a[i],b[i]),c[i]);
		if(maxn[i]==a[i]){
			maxnid[i]=1;
			secmaxn[i]=max(b[i],c[i]);
		}else if(maxn[i]==b[i]){
			maxnid[i]=2;
			secmaxn[i]=max(a[i],c[i]);
		}else{
			maxnid[i]=3;
			secmaxn[i]=max(a[i],b[i]);
		}
	}
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	while(!q3.empty()) q3.pop();
	int ans=0;
	for(int i=1; i<=n; ++i){
		ans+=maxn[i];
		//cout<<maxn[i]<<'m'<<'\n';
		if(maxnid[i]==1){
			q1.push({secmaxn[i]-maxn[i],maxn[i]});
			if(q1.size()>n/2){
				ans+=q1.top().first;
				q1.pop();
				//cout<<"BLOW1";
			}
		}else if(maxnid[i]==2){
			q2.push({secmaxn[i]-maxn[i],maxn[i]});
			if(q2.size()>n/2){
				ans+=q2.top().first;
				q2.pop();
				//cout<<"BLOW2";
			}
		}else{
			q3.push({secmaxn[i]-maxn[i],maxn[i]});
			if(q3.size()>n/2){
				ans+=q3.top().first;
				q3.pop();
				//cout<<"BLOW3";
			}			
		}
	//	cout<<ans<<'\n';
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin>>T; while(T--) Solve();	
	return 0;
} 
/*
求求了别写挂，不写挂我什么都愿意做的！！！！！
如果没有写挂以人格担保 js 一个月！！！！！ 
*/ 
