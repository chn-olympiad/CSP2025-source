#include <bits/stdc++.h>
#define For(i,s,e) for(int i=s;i<=e;i++)
#define dFor(i,s,e) for(int i=s;i>=e;i--)
#define int long long
using namespace std;
const int MaxN=2e5+10;
string x,y,a[MaxN],b[MaxN];
int n,m;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	For(i,1,n)cin>>a[i]>>b[i];
	while(m--){
		cin>>x>>y;
		int ans=0;
		For(i,1,n){
			int l=x.find(a[i]),r=y.find(b[i]);
			if(l==-1 || r==-1 || l!=r)continue;
			string t=x;
			For(j,l,l+b[i].size()-1)t[j]=b[i][j-l];
			if(t==y){ans++;}
		}
		cout<<ans<<endl;
	}
    return 0;
}

