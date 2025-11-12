#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
struct node
{
	string u,v;
};
vector<node>g;
string a,b,x,y,z;
long long n,q,ans,len,l;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>a>>b;
		g.push_back({a,b});
	}
	while(q--){
		ans=0;
		cin>>a>>b;
		l=a.size();
		for(long long i=0;i<n;i++){
			x=g[i].u,y=g[i].v;
			len=x.size();
			for(long long j=0;j+len-1<l;j++){
				if(a.substr(j,x.size())==x){
					z=a;
					z.replace(j,x.size(),y);
					if(z==b){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
