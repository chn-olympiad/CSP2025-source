#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5;
int n,k,a[N+10],cnt,ans;
string c[N+10],d;
map<string,int> m;
struct edge{
	int l,r;
}e[N+10];
string jz(int x){
	string s="";
	if(x==0) s='0'+s;
	for(;x>0;x/=2) {
		s=char(x%2+'0')+s;
	}
	while(s.size()<20) s='0'+s; 
	return s;
}
string mod2(string s,string x){
	string c="";
	for(int i=0;i<20;i++) {
		int b1=(s[i]-'0'),b2=(x[i]-'0');
		c+=char(b1^b2+'0');
	}
	return c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	d=jz(k);
	c[0]=jz(0);
	m[c[0]]=1;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		c[i]=mod2(c[i-1],jz(a[i]));
	}
	for(int i=1;i<=n;i++) {
		string y=mod2(d,c[i]);
		if(m[y]) e[++cnt].l=m[y],e[cnt].r=i;
		m[c[i]]=i+1;
	}
	int L=e[cnt].l;
	if(cnt) ans=1;
	for(int i=cnt-1;i>=1;i--) {
		if(L<=e[i].r) {
			if(L<=e[i].l) L=e[i].l;
		}
		else {
			ans++;
			L=e[i].l;
		}
	}
	printf("%d",ans);
	
	return 0;
}
