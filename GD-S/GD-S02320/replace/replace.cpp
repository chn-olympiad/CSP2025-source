#include<bits/stdc++.h>
#define int long long
const int N=1e4+22;
using namespace std;
int n,q;
map <string,set <string> > m;
bool check(string x,string y,int yyy){
	int awa=0;
	for(int i=0;i<x.size();i++) if(x[i]!=y[i]) awa++;
	return awa==yyy;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		m[x].insert(y);
	}
	while(q--){
		string x,y;
		int cnt=0,yyy=0;
		cin>>x>>y;
		x=" "+x;
		y=" "+y;
		for(int i=1;i<x.size();i++) if(x[i]!=y[i]) yyy++;
		for(int len=1;len<x.size();len++){
			for(int l=1;l+len<=x.size();l++){
				string xx=x.substr(l,len),yy=y.substr(l,len);
				if(xx==yy) continue ;
//				cout<<xx<<' '<<yy<<endl;
				if(m[xx].count(yy) && len>=yyy && check(xx,yy,yyy)) cnt++;
			}
		}
		printf("%lld\n",cnt);
	}
}
