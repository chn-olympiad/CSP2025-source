//17:36
#include<bits/stdc++.h>
#define mk make_pair
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef int Rd;

inline Rd read(){Rd xxx=0,yyy=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')yyy*=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){xxx=(xxx<<1)+(xxx<<3)+(ch^48);ch=getchar();}
return xxx*yyy;
}

const int maxn=500005,maxl=5e6+5,maxnn=1e4+5;

int n,q;
int now1,now2;
string S1,S2,T1,T2;
string S[maxnn][2],T[maxnn][2];
int a[maxl],ans[maxn];
int bt[maxl];
struct node{
	int l,r,id;
	bool operator <(const node&T)const{return l<T.l;}
}o;
node md(int k1,int k2,int k3){
	o.l=k1,o.r=k2,o.id=k3;
	return o;
}
vector<node>qu[maxl][2],b[maxl][2]; 
void add(int x,int y){
	while(x<maxl){
		bt[x]+=y;
		x+=(-x)&x;
	}
}void clr(int x){
	while(x<maxl){
		bt[x]=0;
		x+=(-x)&x;
	}
}int query(int x){
	int ret=0;
	while(x){
		ret+=bt[x];
		x-=(-x)&x;
	}
	return ret;
}

void slv1(){
	for(int i=1;i<=n;i++){
		if(now2>=i)S1=S[i][0],S2=S[i][1];
		else cin>>S1>>S2;
		int l,r,lf,rt,sz=S1.size();
		for(int j=0;j<sz;j++)if(S1[j]=='b'){l=j,lf=j,rt=S1.size()-j;break;}
		for(int j=0;j<sz;j++)if(S2[j]=='b'){r=j;break;}
		if(l-r>0)b[l-r][0].push_back(md(lf,rt,0));
		else b[r-l][1].push_back(md(lf,rt,0));
	}
	for(int i=1;i<=q;i++){
		if(now1==2&&now2>=i)T1=T[i][0],T2=T[i][1];
		else cin>>T1>>T2;
		int l,r,lf,rt,sz=T1.size();
		for(int j=0;j<sz;j++)if(T1[j]=='b'){l=j,lf=j,rt=T1.size()-j;break;}
		for(int j=0;j<sz;j++)if(T2[j]=='b'){r=j;break;}
		if(l-r>0)qu[l-r][0].push_back(md(lf,rt,i));
		else qu[r-l][1].push_back(md(lf,rt,i));
	}
	for(int i=1;i<maxl;i++){
		if((!qu[i][0].size())||(!b[i][0].size()))continue;
		sort(qu[i][0].begin(),qu[i][0].end());
		sort(b[i][0].begin(),b[i][0].end());
		for(int k=0,j=0;k<qu[i][0].size();k++){
			while(j<b[i][0].size()&&b[i][0][j].l<=qu[i][0][k].l)add(b[i][0][j++].r,1);
			ans[qu[i][0][k].id]=query(qu[i][0][k].r);
		}
		for(int k=0;k<b[i][0].size();k++)
			clr(b[i][0][k].r);
	}
	for(int i=0;i<maxl;i++){
		if((!qu[i][1].size())||(!b[i][1].size()))continue;
		sort(qu[i][1].begin(),qu[i][1].end());
		sort(b[i][1].begin(),b[i][1].end());
		for(int k=0,j=0;k<qu[i][1].size();k++){
			while(j<b[i][1].size()&&b[i][1][j].l<=qu[i][1][k].l)add(b[i][1][j++].r,1);
			ans[qu[i][1][k].id]=query(qu[i][1][k].r);
		}
		for(int k=0;k<b[i][1].size();k++)
			clr(b[i][1][k].r);
	} 
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]); 
}


void slv2(){
	int L2=0;
	now1=1;
	for(int i=1;i<=n;i++){
		cin>>S[i][0]>>S[i][1];
		L2+=S[i][0].size();
		now2=i;
		if(L2>2000){slv1();return;}
	}
	now1=2;
	for(int i=1;i<=q;i++){
		cin>>T[i][0]>>T[i][1];
		L2+=T[i][0].size();
		now2=i;
		if(L2>2000){slv1();return;}
	}
	for(int i=1;i<=q;i++){
		cin>>T[i][0]>>T[i][1];
		string F="",G="";
		int len=T[i][0].size(),l=0,r;
		for(int j=0;j<len;j++){
			if(T[i][0][j]!=T[i][1][j]){
				if(!l)l=j;
				r=j;
			}
		}
		for(int j=l;j<=r;j++){
			F=F+T[i][0][j];
			G=G+T[i][1][j];
		}
		int as=0;
		for(int j=1;j<=n;j++){
			for(int k=0,cnt=0;k<S[j][0].size();k++){
				if(F[cnt]==S[j][0][k]&&G[cnt]==S[j][1][k])cnt++;
				if(cnt==F.size()){
					if(k-cnt>l-1||S[j][0].size()-k-1>T[i][0].size()-r-1)break;
					for(int u=k-cnt,v=l-1;u>=0;u--,v--)if(S[j][0][u]!=T[i][0][v])break;
					for(int u=k-cnt,v=l-1;u>=0;u--,v--)if(S[j][1][u]!=T[i][1][v])break;
					for(int u=k+1,v=r+1;u<S[j][0].size();v++,u++)if(S[j][0][u]!=T[i][0][v])break;
					for(int u=k+1,v=r+1;u<S[j][0].size();v++,u++)if(S[j][1][u]!=T[i][1][v])break;
					as++;
					break;
				}
			}
		}
		cout<<as<<endl;
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n<=3000&&q<=3000)slv2();
	else slv1();
	return 0;
}
