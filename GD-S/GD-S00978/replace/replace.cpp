#include<bits/stdc++.h>
using namespace std;
const int N=2e5+550;
int n,q;
struct node{
	string o,n;int c,x,y;
}s[N];
map<int,vector<int> > v;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].o>>s[i].n;
		int x,y;
		for(int j=0;j<s[i].o.size();j++){
			if(s[i].o[j]=='b'){
				x=j;
				break;
			}
		}for(int j=0;j<s[i].n.size();j++){
			if(s[i].n[j]=='b'){
				y=j;
				break;
			}
		}
		s[i].x=x;
		s[i].y=y;
		s[i].c=x-y;
		v[x-y].push_back(i);
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int x,y,ans=0;
		for(int j=0;j<a.size();j++){
			if(a[j]=='b'){
				x=j;
				break;
			}
		}
		for(int j=0;j<b.size();j++){
			if(b[j]=='b'){
				y=j;
				break;
			}
		}
		for(auto u:v[x-y]){
			if(s[u].x<=x&&s[u].y<=y) ans++;
		}
		printf("%lld\n",ans);
//		cout<<q;
	}
	return 0;
}
