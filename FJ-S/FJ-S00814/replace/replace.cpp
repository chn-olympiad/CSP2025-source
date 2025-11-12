#include<bits/stdc++.h>
using namespace std;
struct str{
	string a,b;
};
int n,q,l,r,d,p,o,s;
string x,y,z[3];
map<string,int> m;
vector<int> v;
vector<str> f[200001];
void ff(){
	cin>>x>>y,z[0]=z[1]=z[2]="",l=0,r=x.size();
	while(l<r&&x[l]==y[l]) z[0]+=x[l],l++;
	while(l<r&&x[r-1]==y[r-1]) z[2]+=x[r-1],r--;
	for(int i=l;i<r;i++) z[1]+=x[i];
}
void h(string a,string b,string c,string e){
	r=a.size(),d=b.size(),p=c.size(),o=e.size();
	if(r>=p&&d>=o){
		for(int i=0;i<o;i++) if(b[i]!=e[i]) return;
		for(int i=0;i<p;i++) if(a[i]!=c[i]) return;
		s++;
	}
}
void g(){
	if(x.size()!=y.size()) return;
	ff();
	if(!m[z[1]]) return;
	l=v[m[z[1]]];
	for(int i=f[l].size();i--;h(z[0],z[2],f[l][i].a,f[l][i].b));
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while(n--){
		ff();
		if(!m[z[1]]) m[z[1]]=d,v.push_back(p),f[p].push_back({z[0],z[2]}),d++,p++;
		else f[v[m[z[1]]]].push_back({z[0],z[2]});
	}
	while(q--) s=0,g(),cout<<s<<endl;
	return 0;
}
