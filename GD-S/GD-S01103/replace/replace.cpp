#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
char Begin;
const int N=2e5+15;
const int M=5e6+15;
const ull B=1331;
char s[M];
char p[M],q[M];
int n,Q,m,cnt;
int m1,m2,mx=5e6;
int l[N],r[N];
int L[N],R[N];
ull a[M],b[M];
int pre[M],suf[M];
ull base[M],S,P;
ll ans;
struct node{ull s,t;};
bool operator<(node x,node y){
	if(x.s==y.s)return x.t<y.t;
	return x.s<y.s;
}
std::map<node,int>mp;
struct AC{
	int son[30],dep;
	int fail,up;
	ull end;
}t[M];
int d[M],st,now;
void Build(int l,int r,ull to){
	now=S=0;
	fr(i,l,r){
		S=S*B+s[i];
		int u=s[i]-'a';
		if(!t[now].son[u]){
			t[now].son[u]=++cnt;
			t[cnt].dep=t[now].dep+1;
		}now=t[now].son[u];
	}
	t[now].end=S;
	mp[{t[now].end,to}]++;
}
void get_fail(){
	st=0;
	fr(i,0,25){
		if(!t[0].son[i])continue;
		d[++st]=t[0].son[i];
	}
	fr(i,1,st)fr(j,0,25){
		if(t[d[i]].son[j]){
			t[t[d[i]].son[j]].fail=t[t[d[i]].fail].son[j];
			d[++st]=t[d[i]].son[j];
			if(!t[d[st]].up){
				t[d[st]].up=t[t[d[st]].fail].up;
				if(t[t[d[st]].fail].end)
					t[d[st]].up=t[d[st]].fail;
			}
		}else t[d[i]].son[j]=t[t[d[i]].fail].son[j];
	}
}
char End;
int main(){
	// std::cerr<<(&End-&Begin)/1024/1024<<std::endl;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	base[0]=1;
	fr(i,1,5e6)base[i]=base[i-1]*B;
	scanf("%d%d",&n,&Q);
	fr(i,1,n){
		l[i]=m+1;scanf("%s",s+m+1);m=strlen(s+1);r[i]=m;
		L[i]=m+1;scanf("%s",s+m+1);m=strlen(s+1);R[i]=m;
		P=0;fr(j,L[i],R[i])P=P*B+s[j];
		Build(l[i],r[i],P);
	}get_fail();
	while(Q--){
		scanf("%s",p+1);m1=strlen(p+1);
		scanf("%s",q+1);m2=strlen(q+1);
		fr(i,1,m1)a[i]=a[i-1]*B+p[i];
		fr(i,1,m2)b[i]=b[i-1]*B+q[i];
		pre[0]=1;
		fr(i,1,m1){
			pre[i]=pre[i-1];
			if(p[i]!=q[i])pre[i]=0;
		}
		suf[m1+1]=1;
		for(int i=m1,j=m2;i;i--,j--){
			suf[i]=suf[i+1];
			if(j<1){suf[i]=0;continue;}
			if(p[i]!=q[j])suf[i]=0;
		}
		now=ans=0;
		fr(i,1,m1){
			int u=p[i]-'a';
			int k=m2-m1+i;
			now=t[now].son[u];
			if(!suf[i+1])continue;
			for(int j=now;j;j=t[j].up){
				if(!t[j].end)continue;
				if(!pre[i-t[j].dep])break;
				ull A=b[k]-b[k-t[j].dep]*base[t[j].dep];
				ans+=mp[{t[j].end,A}];
			}
		}printf("%lld\n",ans);
		fr(i,1,m1)p[i]=0;
		fr(i,1,m2)q[i]=0;
	}
}