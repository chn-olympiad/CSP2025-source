//replace
#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
int n,m,l,r,cnt;
string x,y;
int a[200010],b[200010],c[200010],d[200010],s[200010];
vector<int> u,v,w,z;
pii p[200010],t;
int fpow(int x,int k){
	int r=1;
	while(k){
		if(k&1) r*=x;
		x*=x;
		k>>=1;
	}
	return r;
}
pii gt(string a,string b){
	int l,r;
	for(l=0;l<a.size()&&a[l]==b[l];l++);
	for(r=a.size()-1;r>=0&&a[r]==b[r];r--);
	return {l,r};
}
vector<int> hsh(string s,int p){
	vector<int> r;
	r.push_back(s[0]-'a');
	for(int i=1;i<s.size();i++) r.push_back(r.back()*p+s[i]-'a');
	return r;
}
int hshi(string s,int p){
	int r=s[0]-'a';
	for(int i=1;i<s.size();i++) r=r*p+s[i]-'a';
	return r;
}
int clc(vector<int> v,int l,int r,int p){
	if(!l) return v[r];
	else return v[r]-v[l-1]*fpow(p,r-l+1);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		p[i]=gt(x,y);
		a[i]=hshi(x,101);
		b[i]=hshi(x,10007);
		c[i]=hshi(y,101);
		d[i]=hshi(y,10007);
		s[i]=x.size();
	}
	while(m--){
		cin>>x>>y;
		t=gt(x,y);
		u=hsh(x,101);
		v=hsh(x,10007);
		w=hsh(y,101);
		z=hsh(y,10007);
		cnt=0;
		for(int i=1;i<=n;i++){
			if(t.s-t.f!=p[i].s-p[i].f) continue;
			l=t.f-p[i].f;
			r=l+s[i]-1;
			if(l<0||r>x.size()) continue; 
			if(clc(u,l,r,101)==a[i]&&clc(v,l,r,10007)==b[i]&&
				clc(w,l,r,101)==c[i]&&clc(z,l,r,10007)==d[i]) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
