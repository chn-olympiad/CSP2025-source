#include<bits/stdc++.h>
#define il inline
#define ull unsigned long long
using namespace std;
const int sz1=200000;
const ull mul=11451419;
const ull mul2=1919810123;
int n,q,fir,lst,tot,ans;
string s1,s2,s,t1,t2;
mt19937_64 rd(time(0));
const int sz2=10000000;
int cnt;
int to[sz2+5][26],sum[sz2+5];
ull hsh[26],pw[sz2+5],nsum,nsum2;
void ins(int x){
	for(int i=0;i<s.size();i++){
		if(!to[x][s[i]-'a']) to[x][s[i]-'a']=++cnt;
		x=to[x][s[i]-'a'];
	}
	++sum[x];
}
const int mod=2e7+9;
int p;
ull key[mod+5];
int val[mod+5];
il void add1(ull x,int v){
	p=x%mod;
	while(key[p]) p=(p==mod-1?0:p+1);
	key[p]=x;val[p]=v;
}
il int qry1(ull x){
	p=x%mod;
	while(key[p]){
		if(key[p]==x) return val[p];
		p=(p==mod-1?0:p+1);
	}
	return 0;
}
ull key2[mod+5];
ull val2[mod+5];
il void add2(ull x,int v){
	p=x%mod;
	while(key2[p]) p=(p==mod-1?0:p+1);
	key2[p]=x;val2[p]=v;
}
il int qry2(ull x){
	p=x%mod;
	while(key2[p]){
		if(key2[p]==x){
			if(val2[p]) return val2[p];
			return -1;
		}
		p=(p==mod-1?0:p+1);
	}
	return 0;
}
void upd(int x,ull h,int s){
	add2(h,s);
	for(int i=0;i<26;i++)
		if(to[x][i]) upd(to[x][i],h*mul+hsh[i],s+sum[to[x][i]]);
}
ull hsum[sz2+5],nsum3;
int l,r,mid,bans,ncnt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i=0;i<26;i++) hsh[i]=rd();
	pw[0]=1;
	for(int i=1;i<=sz2;i++) pw[i]=pw[i-1]*mul;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;fir=lst=-1;
		for(int j=0;j<s1.size();j++)
			if(s1[j]!=s2[j]){
				if(fir==-1) fir=j;
				lst=j;
			}
		if(fir==-1) continue;
		nsum=0;
		for(int i=0;i<=lst;i++) nsum=nsum*mul+hsh[s1[i]-'a'];
		nsum2=0;
		for(int i=fir;i<=lst;i++) nsum2=nsum2*mul+hsh[s2[i]-'a'];
		nsum=nsum*mul2+nsum2;
		if(!qry1(nsum)) add1(nsum,++cnt);
		s=s1.substr(lst+1,s1.size()-1-lst);
		ins(qry1(nsum));
	}
	for(int i=0;i<mod;i++) if(key[i]) upd(val[i],key[i],sum[val[i]]);
	while(q--){
		cin>>t1>>t2;fir=lst=-1;
		for(int i=0;i<t1.size();i++)
			if(t1[i]!=t2[i]){
				if(fir==-1) fir=i;
				lst=i;
			}
		ans=0;
		nsum2=0;
		for(int i=fir;i<=lst;i++) nsum2=nsum2*mul+hsh[t2[i]-'a'];
		hsum[lst]=0;
		for(int i=lst+1;i<t1.size();i++) hsum[i]=hsum[i-1]*mul+hsh[t1[i]-'a'];
		nsum=0;
		for(int i=fir+1;i<=lst;i++) nsum=nsum*mul+hsh[t1[i]-'a'];
		for(int i=fir;~i;i--){
			nsum+=pw[lst-i]*hsh[t1[i]-'a']; 
			nsum3=nsum*mul2+nsum2;
			if(qry1(nsum3)){
				l=lst,r=t1.size()-1,bans=0;
				ncnt=qry2(nsum3*pw[r-lst]+hsum[r]);
				while(l<=r){
					mid=(l+r)>>1;
					ncnt=qry2(nsum3*pw[mid-lst]+hsum[mid]);
					if(ncnt) bans=ncnt,l=mid+1;
					else r=mid-1;
				}
				if(bans!=-1) ans+=bans;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 1
abc bca
abca bcaa
abca bcaa
abcc bcac
aabca abcaa
*/
