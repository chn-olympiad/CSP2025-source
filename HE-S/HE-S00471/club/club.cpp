#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e7+100;
struct Edge {
	int a;
	int b;
	int c;
	int end;
}s[N];
bool cmp(Edge x,Edge y){
	if(x.a==y.a){
		if(x.b==y.b){
			x.c>y.c;
		}else {
			return x.b>y.b;
		}
	}else {
		return x.a>y.a;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		bool flag1=1;
		bool flag2=1;
		int ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].end=max(s[i].a,max(s[i].b,s[i].c));
			if(s[i].b){
				flag1=0;
			}
			if(s[i].c){
				flag2=0;
			}
		}
		sort(s+1,s+1+n,cmp);
		if(n==2){
			if(s[1].end==s[1].a){
				if(s[2].end!=s[2].a){
					cout<<s[1].end+s[2].end<<'\n';
					continue;
				}else {
					cout<<max(s[1].a+s[2].b,max(max(s[1].b+s[2].a,s[1].c+s[2].a),s[1].a+s[2].c))<<'\n';
				}
			}
		}
		if(flag1&&flag2){
			for(int i=1;i<=n/2;i++){
				ans+=s[i].a;
			}
			cout<<ans<<'\n';
			continue;
		}else if(flag1){
			for(int i=1;i<=n/2;i++){
				ans+=s[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=s[i].b;
			}
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}
