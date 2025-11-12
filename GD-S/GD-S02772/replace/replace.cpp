#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
using namespace std;
const int N=5e6+5,bs=37,p=1e9+7,bs2=41;
int n,q;
struct node{
	int l,r;
	unsigned int lk,rk;
};
map<pair<unsigned int,ll>,vector<node> > g;
unsigned int sum[N],powr[N];
string a,b;
int qq[200];
int bk(char xx){
	return qq[xx];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	powr[0]=1;
	srand(time(0));
	for(int i='a';i<='z';i++)
		qq[i]=rand()+21;
	for(int i=1;i<=5e6;i++)
		powr[i]=powr[i-1]*bs;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		int len=a.size();
		int l,r;
		for(l=0;l<len;l++)
			if(a[l]!=b[l]) break;
		for(r=len-1;r>=0;r--)
			if(a[r]!=b[r]) break;
		unsigned int s1=0,s2=0,sl=0,sr=0;
		ll ds1=0,ds2=0;
		for(int j=l;j<=r;j++)
			s1*=bs,s1+=bk(a[j]),s2*=bs,s2+=bk(b[j]);
		for(int j=l;j<=r;j++)
			ds1*=bs2,ds1+=bk(a[j]),ds1%=p,ds2*=bs,ds2+=bk(b[j]),ds2%=p;
		for(int j=0;j<l;j++)
			sl*=bs,sl+=bk(a[j]);
		for(int j=r+1;j<len;j++)
			sr*=bs,sr+=bk(a[j]);
		s2-=s1;ds2-=ds1;
		r=len-1-r;
		node cs=(node){l,r,sl,sr};
		g[mkp(s2,ds2)].pb(cs);
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		int len=a.size();
		if(len!=b.size()) {
			cout<<0<<"\n";continue;
		}
		int l,r;
		for(l=0;l<len;l++)
			if(a[l]!=b[l]) break;
		for(r=len-1;r>=0;r--)
			if(a[r]!=b[r]) break;
		unsigned int s1=0,s2=0,sl=0,sr=0;
		ll ds1=0,ds2=0;
		for(int j=l;j<=r;j++)
			s1*=bs,s1+=bk(a[j]),s2*=bs,s2+=bk(b[j]);
		for(int j=l;j<=r;j++)
			ds1*=bs2,ds1+=bk(a[j]),ds1%=p,ds2*=bs,ds2+=bk(b[j]),ds2%=p;
		s2-=s1;ds2-=ds1;
		int ans=0;
		sum[0]=0;
		for(int j=0;j<len;j++){
			if(j!=0) sum[j]=sum[j-1];
			sum[j]*=bs,sum[j]+=bk(a[j]);
		}
		//cout<<g[s2].size();
		for(int j=0;j<g[mkp(s2,ds2)].size();j++){
			//cout<<j<<"+\n";
			node x=g[mkp(s2,ds2)][j];
			if(x.l>l||len-1-r<x.r) continue;
			if(x.l==l) {
				if(sum[l-1]!=x.lk) continue;
			}
			else {
				if(sum[l-1]-sum[l-1-x.l]*powr[x.l]!=x.lk) continue;
			}
			if(sum[r+x.r]-sum[r]*powr[x.r]!=x.rk) {continue;}
			ans++;
		}
		cout<<ans<<"\n";
	}
	/*
	5 1
	abc abd
	cb db
	abcb abdb
	c d
	bcb bdb
	abcb abdb
	*/
	return 0;
}
