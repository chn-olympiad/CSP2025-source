#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int T,n;

struct stu {
	int a,b,c;
	int ma,mb,mc;
} p[100001];
map<unsigned long long,int>m;
map<unsigned long long,bool>s;

const unsigned long long big=1e5;

int dfs(int now,int a,int b,int c) {
	unsigned long long tmp=now*big*big*big+a*big*big+b*big+c;
	if(s[tmp]) return m[tmp];
	if(now>n) return 0;
	else {
		int temp=0;
		if(a>0) temp=max(temp,dfs(now+1,a-1,b,c)+p[now].a);
		if(b>0) temp=max(temp,dfs(now+1,a,b-1,c)+p[now].b);
		if(c>0) temp=max(temp,dfs(now+1,a,b,c-1)+p[now].c);
		m[tmp]=max(m[tmp],temp);
		s[tmp]=1;
		return m[tmp];
	}
}

int main(int argc,char**argv) {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>T;
	while(T--) {
		cin>>n;
		bool tp1=1,tp2=1;
		int ma=0,mb=0,mc=0; 
		for(int i=1; i<=n; ++i) {
			cin>>p[i].a>>p[i].b>>p[i].c;
			ma+=p[i].a;
			mb+=p[i].b;
			mc+=p[i].c;	
		}
		
		for(int i=1;i<=n;++i) {
			p[i].ma=p[i].a*2-p[i].b*2-p[i].c*2-ma+mb+mc;
			p[i].mb=p[i].b*2-p[i].a*2-p[i].c*2+ma-mb+mc;
			p[i].mc=p[i].c*2-p[i].a*2-p[i].b*2+ma+mb-mc;
		}

		for(int i=1;i<=n;++i) {
			cout<<p[i].ma<<' '<<p[i].mb<<' '<<p[i].mc<<'\n';
		}

	}

	return 0;
}
