#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define ull unsigned long long
#define N 200010
#define For(i,a,b) for(register int i=a;i<=b;++i)
#define Rof(i,a,b) for(register int i=a;i>=b;--i)
#define ls x<<1
#define rs x<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
#define pb push_back
#define mk make_pair
#define pque priority_queue
#define pii pair<ll,ll>
#define fi first
#define se second

using namespace std;
const ull B=23333;
ull mi[5000010];
char s1[5000010],s2[5000010];
ull hsh1[5000010];
int sz[N];
vector<ull >hsh[N];
vector<char >p1[N],p2[N];
ll n,q;

ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ull qry(int op,int l,int r){
	return hsh[op][r]-hsh[op][l-1]*mi[r-l+1];
}
ull qry1(int l,int r){
	return hsh1[r]-hsh1[l-1]*mi[r-l+1];
}
void sub1(){
	while(q--){
		cin.getline(s1+1,5000010,' ');
		cin.getline(s2+1,5000010);
		int len1=strlen(s1+1),len2=strlen(s2+1);
		if(len1!=len2){
			cout<<0<<endl;
			continue;
		}
		int pl=len1+1,pr=0;
		For(i,1,len1){
			if(s1[i]!=s2[i]){
				pl=min(pl,i);
				pr=max(pr,i);
			}
			ull p=(s1[i]-'a')*26+(s2[i]-'a');
			hsh1[i]=hsh1[i-1]*B+p;
		}
		ull now=qry1(pl,pr);
		int ans=0;
		For(i,1,n){
			For(j,1,sz[i]){
				if(j+(pr-pl)>sz[i]) break;
				if(qry(i,j,j+pr-pl)==now){
					int nowl=pl-(j-1),nowr=nowl+sz[i]-1;
					if(nowl<1 || nowr>len1) continue;
					if(qry(i,1,sz[i])==qry1(nowl,nowr)) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
struct node{
	int l,r;
	int bh;
};
vector<node >po[10000010];
int ans[N];
int c[5000010];
void add(int x,int k){
	while(x<=5000005){
		c[x]+=k;
		x+=(x&(-x));
	}
}
int qry2(int x){
	int p=0;
	while(x){
		p+=c[x];
		x-=(x&(-x));
	}
	return p;
}
void sub2(){
	For(i,1,n){
		int pos1,pos2;
		For(j,1,sz[i]){
			if(p1[i][j]=='b') pos1=j;
			if(p2[i][j]=='b') pos2=j;
		}
		po[pos1-pos2+5000005].pb((node){min(pos1,pos2),sz[i]-max(pos1,pos2)+1,0});
	}
	int pcnt=0;
	For(i,1,q){
		cin.getline(s1+1,5000010,' ');
		cin.getline(s2+1,5000010);
		pcnt++;
		int len1=strlen(s1+1),len2=strlen(s2+1);
		if(len1!=len2) continue;
		node pp={0,0,0};
		pp.bh=pcnt;
		int pos1,pos2;
		For(j,1,len1){
			if(s1[j]=='b') pos1=j;
			if(s2[j]=='b') pos2=j;
		}
		pp.l=min(pos1,pos2);
		pp.r=len1-max(pos1,pos2)+1;
		po[pos1-pos2+5000005].pb(pp);
	}
	For(i,0,10000009){
		if(!po[i].size()) continue;
		sort(po[i].begin(),po[i].end(),[&](node x,node y){return x.l==y.l?x.r==y.r?x.bh<y.bh:x.r<y.r:x.l<y.l;});
		for(node j:po[i]){
			int r=j.r,bh=j.bh;
			if(!bh) add(r,1);
			else ans[bh]=qry2(r);
		}
		for(node j:po[i]){
			int r=j.r,bh=j.bh;
			if(!bh) add(r,-1);
		}
	}
	For(i,1,q) cout<<ans[i]<<endl;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	mi[0]=1;
	For(i,1,5000005) mi[i]=mi[i-1]*B;
	n=read(),q=read();
	For(i,1,n){
		cin.getline(s1+1,5000010,' ');
		cin.getline(s2+1,5000010);
		sz[i]=strlen(s1+1);
		hsh[i].resize(sz[i]+1);
		p1[i].resize(sz[i]+1);
		p2[i].resize(sz[i]+1);
		For(j,1,sz[i]){
			ull p=(s1[j]-'a')*26+(s2[j]-'a');
			p1[i][j]=s1[j],p2[i][j]=s2[j];
			hsh[i][j]=hsh[i][j-1]*B+p;
		}
	}
	ll sum=0;
	For(i,1,n) sum+=sz[i];
	if(sum*q<=2e7) sub1();
	else sub2();
	return 0;
}
