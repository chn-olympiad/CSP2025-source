#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,g,pcz[200005],pdz[200005]; 
vector<int> wy[200005];
struct pa{
	string a,b;
	int sz;
}s[400005];
string x,y,z,qw;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		s[i].sz=s[i].a.size();
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int ans=0;
		for(int j=1;j<=n;j++){
			z=x;
			while(1){
				g=z.find(s[j].a);
				if(g!=-1){
					qw=x.substr(0,g)+s[j].b+x.substr(g+s[j].sz,y.size()-1-g+s[j].sz);
					if(qw==y){
//						cout<<qw<<" "<<y<<"\n";
						ans++;
						break;
					}
					z[g]=' ';
				}
				else break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*

string x,y,qe,wr,awa,z;
map<string,int> fd; 
bool cmp(pa qw,pa we){
	if(qw.sz!=we.sz) return qw.sz<we.sz;
	return qw.a<we.a;
}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++){
		l=0,r=s[i].sz-1;
		while(l<=r&&(s[i].a[l]==s[i].b[l]||s[i].a[r]==s[i].b[r])){
			if(s[i].a[l]==s[i].b[l]) l++;
			else r--;
		}
		if(l<=r) s[i+n].a=s[i].a.substr(l,r-l+1),s[i+n].b=[i].b.substr(l,r-l+1);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++){
		if(s[i+n].a==s[j+n].a&&s[i+n].b==s[j+n].b){
			
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
	}
*/
