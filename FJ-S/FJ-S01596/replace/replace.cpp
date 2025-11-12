#include<bits/stdc++.h>
using namespace std;
namespace umrofcen{
	using L=unsigned long long;
	const unsigned P=998244353,Q=998244853,R=1000000007;
	char c,s[5005005],t[5005005];int n,m,o,i,j,k,l,d,Z,ZZ,qq,ll,rr,S[200200],T[200200],X[3003003],Y[3003003],a[26][3003003],w[3003003],O[200200];unsigned x,y,z;struct q{int x,y,z;q(){}q(unsigned a,unsigned b,unsigned c){x=a,y=b,z=c;}bool operator<(q a)const{return x^a.x?x<a.x:z>a.z;}}e[600600];pair<pair<int,int>,int> pp;map<pair<pair<int,int>,int>,int> M;
	void PP(int x,int k){for(;x<=Z;x+=x&-x)w[x]+=k;}
	int QQ(int x){int s=0;for(;x;x&=x-1)s+=w[x];return s;}
	void D(int p){X[p]=++ZZ;for(int i=26;i--;a[i][p]?D(a[i][p]),0:0);Y[p]=ZZ;}
	void N(){
		for(cin>>n>>m;o++^n;){
			for(cin>>s>>t,i=0,l=strlen(s)-1;i<=l&&s[i]==t[i];++i);
			if(i<=l){
				for(j=l;s[j]==t[j];--j);
				for(k=i,x=y=z=0;k<=j;++k)x=(L(x)*31+(s[k]^96))%P,y=(L(y)*37+(s[k]^96))%Q,z=(L(z)*41+(s[k]^96))%R;
				for(k=i;k<=j;++k)x=(L(x)*31+(t[k]^96))%P,y=(L(y)*37+(t[k]^96))%Q,z=(L(z)*41+(t[k]^96))%R;
				if(!M[pp=make_pair(make_pair(x,y),z)])M[pp]=++Z;
				for(d=M[pp],k=i-1;k>=0;--k)d=a[c=s[k]-97][d]?a[c][d]:a[c][d]=++Z;S[o]=d;
				for(d=M[pp],k=j+1;k<=l;++k)d=a[c=s[k]-97][d]?a[c][d]:a[c][d]=++Z;T[o]=d;
			}
		}
		for(i=0;i^Z;)if(!X[++i])D(i);
		for(i=0;i^n;)if(S[++i])e[qq++]=q(X[S[i]],X[T[i]],Y[T[i]]),e[qq++]=q(Y[S[i]]+1,-X[T[i]],Y[T[i]]);
		for(o=0;o++^m;){
			if(cin>>s>>t,strlen(s)==(l=strlen(t))){
				for(i=0,--l;i<=l&&s[i]==t[i];++i);
				for(j=l;s[j]==t[j];--j);
				for(k=i,x=y=z=0;k<=j;++k)x=(L(x)*31+(s[k]^96))%P,y=(L(y)*37+(s[k]^96))%Q,z=(L(z)*41+(s[k]^96))%R;
				for(k=i;k<=j;++k)x=(L(x)*31+(t[k]^96))%P,y=(L(y)*37+(t[k]^96))%Q,z=(L(z)*41+(t[k]^96))%R;
				if(M[pp=make_pair(make_pair(x,y),z)]){
					for(d=M[pp],k=i-1;k>=0;--k,d=a[c][d])if(!a[c=s[k]-97][d])break;ll=d;
					for(d=M[pp],k=j+1;k<=l;++k,d=a[c][d])if(!a[c=s[k]-97][d])break;rr=d;
					e[qq++]=q(X[ll],X[rr],-o);
				}
			}
		}
		for(i=0,sort(e,e+qq);i^qq;++i)if(e[i].z<0)O[-e[i].z]=QQ(e[i].y);
		else if(e[i].y<0)PP(-e[i].y,-1),PP(e[i].z+1,1);
		else PP(e[i].y,1),PP(e[i].z+1,-1);
		for(i=0;i^m;cout<<O[++i]<<'\n');
	}
};
int main(){return freopen("replace.in","r",stdin),freopen("replace.out","w",stdout),cin.tie(nullptr),ios::sync_with_stdio(false),umrofcen::N(),0;}
