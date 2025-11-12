#include<bits/stdc++.h>
#define f(i,a,b,n) for(int i=a;i<=b;i+=n)
using namespace std;
int n,q,ans;
struct node{
	string s,t;
	int lens,lent;
}c[200005],m;
bool cmp(node a,node b){
	return a.lens<b.lens;
}
string gr(string y,int l,int r){
	string rew;
	f(i,l,r,1) rew+=y[i];
	return rew;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	f(i,1,n,1) cin>>c[i].s>>c[i].t,c[i].lens=c[i].lent=(int)c[i].s.size();
	sort(c+1,c+n+1,cmp);
	while(q--){
		cin>>m.s>>m.t;
		m.lens=(int)m.s.size(),m.lent=(int)m.t.size();
		ans=0;
		if(m.lens!=m.lent){
			cout<<0<<endl;
			continue;
		}
		f(i,0,m.lens-1,1) f(j,1,n,1){
			if(i+c[j].lens>m.lens) break;
			if(gr(m.s,0,i-1)==gr(m.t,0,i-1)&&gr(m.s,i+c[j].lens,m.lens)==gr(m.t,i+c[j].lent,m.lent)&&gr(m.s,i,i+c[j].lens-1)==c[j].s&&gr(m.t,i,i+c[j].lent-1)==c[j].t) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
