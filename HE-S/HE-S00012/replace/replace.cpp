#include<bits/stdc++.h>
#define IL inline
#define mp make_pair
#define pb push_back
#define rpt(a,b,c) for(int a=b;a<=c;a++)
#define tpr(a,b,c) for(int a=b;a>=c;a--)
using namespace std;
typedef long long LL;
const int N=5e6+10;
namespace HASH{
	const int K=3,p[3]={998244353,1000000009,1000000007},bs=799;
	IL int add(const int &a,const int &b,const int &i){return a+b>p[i]?a+b-p[i]:a+b;}
	IL int mul(const int &a,const int &b,const int &i){return 1ull*a*b%p[i];}
	struct info{
		int a[K];
		info(){rpt(i,0,K-1)a[i]=0;}
		info(const int &x){rpt(i,0,K-1)a[i]=x%p[i];}
		IL info operator + (const info &f)const{info g;rpt(i,0,K-1)g.a[i]=add(a[i],f.a[i],i);return g;}
		IL info operator - (const info &f)const{info g;rpt(i,0,K-1)g.a[i]=add(a[i],p[i]-f.a[i],i);return g;}
		IL info operator * (const info &f)const{info g;rpt(i,0,K-1)g.a[i]=mul(a[i],f.a[i],i);return g;}
		IL bool operator == (const info &f)const{rpt(i,0,K-1)if(a[i]!=f.a[i])return 0;return 1;}
		IL bool operator != (const info &f)const{return !(*this==f);}
		IL bool operator < (const info &f)const{rpt(i,0,K-1)if(a[i]!=f.a[i])return a[i]<f.a[i];return 0;}
	}a[N],b[N],qp[N];
	void qpinit(int n){
		qp[0]=info(1);
		rpt(i,1,n)qp[i]=qp[i-1]*info(bs);
	}
	IL void hinit(char s[],info a[],int n){
		rpt(i,1,n)a[i]=a[i-1]*info(bs)+info(s[i]);
	}
	IL info reget(char s[],int n){
		info ans;
		rpt(i,1,n)ans=ans*info(bs)+info(s[i]);
		return ans;
	}
	IL info Get(info a[],int l,int r){
		if(l>r)return info(0);
		return a[r]-a[l-1]*qp[r-l+1];
	}
}using namespace HASH;
int pos[N],tp;
map<info,map<info,int> > vis;
int n,m;
char x[N],y[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	rpt(i,1,n){
		scanf("%s%s",x+1,y+1);
		int k=strlen(x+1);
		pos[++tp]=k,vis[reget(x,k)][reget(y,k)]++;
	}
	sort(pos+1,pos+tp+1),tp=unique(pos+1,pos+tp+1)-pos-1;
	qpinit(pos[tp]);
	while(m--){
		scanf("%s%s",x+1,y+1);
		int k=strlen(x+1);
		hinit(x,a,k),hinit(y,b,k);
		int ans=0;
		tpr(i,k,1){
			if(Get(a,i+1,k)!=Get(b,i+1,k))break;
			tpr(j,tp,1)if(pos[j]<=i){
				if(Get(a,1,i-pos[j])!=Get(b,1,i-pos[j]))break;
				info A=Get(a,i-pos[j]+1,i),B=Get(b,i-pos[j]+1,i);
				if(vis[A].find(B)!=vis[A].end())ans+=vis[A][B];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
