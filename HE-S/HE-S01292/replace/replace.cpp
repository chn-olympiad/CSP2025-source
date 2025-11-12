#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
typedef long long ll;
const int N=2e5+100,M=5e6+100;
int n,m,len;
struct node{
	string x,y;
	int id,l,r,px,py,ch;
}p[N],q[N];
bool check(){
	
	for(int i=1;i<=n;i++){
		bool flag=0;
		for(int j=0;j<p[i].x.size();j++){
			if(p[i].x[j]=='a')continue;
			else if(p[i].x[j]=='b'){
				if(flag)return 0;
				flag=1;
			}
			else return 0;
		}
		flag=0;
		for(int j=0;j<p[i].y.size();j++){
			if(p[i].y[j]=='a')continue;
			else if(p[i].y[j]=='b'){
				if(flag)return 0;
				flag=1;
			}
			else return 0;
		}
	}
	for(int i=1;i<=m;i++){
		bool flag=0;
		for(int j=0;j<q[i].x.size();j++){
			if(q[i].x[j]=='a')continue;
			else if(q[i].x[j]=='b'){
				if(flag)return 0;
				flag=1;
			}
			else return 0;
		}
		flag=0;
		for(int j=0;j<q[i].y.size();j++){
			if(q[i].y[j]=='a')continue;
			else if(q[i].y[j]=='b'){
				if(flag)return 0;
				flag=1;
			}
			else return 0;
		}
	}
	return 1;
}
bool cmp(node fir,node sec){
	return fir.ch==sec.ch?fir.l<sec.l:fir.ch<sec.ch;
}
struct Bit{
	#define lowbit(x) (x&(-x))
	int t[M];
	void updata(int x,int y){
		for(int i=x;i<=len;i+=lowbit(i))t[i]+=y;
	}
	int query(int x){
		int res=0;
		for(int i=x;i>=1;i-=lowbit(i))res+=t[i];
		return res;
	}
}bt;
int ans[N];
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<p[i].x.size();j++){
			if(p[i].x[j]=='b'){
				p[i].px=j;
			}
		}
		for(int j=0;j<p[i].y.size();j++){
			if(p[i].y[j]=='b'){
				p[i].py=j;
			}
		}
		p[i].ch=p[i].px-p[i].py;
		p[i].l=p[i].px;
		p[i].r=p[i].y.size()-p[i].py-1;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<q[i].x.size();j++){
			if(q[i].x[j]=='b'){
				q[i].px=j;
			}
		}
		for(int j=0;j<q[i].y.size();j++){
			if(q[i].y[j]=='b'){
				q[i].py=j;
			}
		}
		q[i].ch=q[i].px-q[i].py;
		q[i].l=q[i].px;
		q[i].r=q[i].y.size()-q[i].py-1;
	}
	sort(p+1,p+n+1,cmp);
	sort(q+1,q+m+1,cmp);
	cerr<<"A"<<endl;
	for(int i=1,j=1,las=0;i<=m;i++){
		while(j<=n){
			if(p[j].ch>q[i].ch)break;
			else if(p[j].ch==q[i].ch){
				if(p[j].l>q[i].l)break;
				bt.updata(p[j].r,1);
				j++;
			}
			else j++;
		}
		if(q[i].x.size()!=q[i].y.size())continue;
		ans[q[i].id]=bt.query(q[i].r);
		if(q[i].ch!=q[i+1].ch){
			for(int k=las+1;k<=j;k++){
				bt.updata(p[j].r,-1);
			}
			las=j;
		}
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}
const ull base=23333;
ull ha[N],hb[N],pw[N],hx[N],hy[N];
inline ull Hx(int l,int r){
	if(l==0)return hx[r];
	else return hx[r]-hx[l-1];
}
inline ull Hy(int l,int r){
	if(l==0)return hy[r];
	else return hy[r]-hy[l-1];
}
void solve2(){
	pw[0]=1;
	for(int i=1;i<N;i++)pw[i]=pw[i-1]*base;
	for(int i=1;i<=n;i++){
		for(int j=0;j<p[i].x.size();j++){
			ha[i]+=pw[j]*p[i].x[j];
		}
		for(int j=0;j<p[i].y.size();j++){
			hb[i]+=pw[j]*p[i].y[j];
		}
	}
	for(int i=1;i<=m;i++){
		if(q[i].x.size()!=q[i].y.size()){
			puts("0");
			continue;
		}
		int res=0;;
		for(int j=0;j<q[i].x.size();j++){
			hx[j]=q[i].x[j];
			for(int k=j+1;k<q[i].x.size();k++)hx[k]=(hx[k-1]+pw[k-j]*q[i].x[k]);
			hy[j]=q[i].y[j];
			for(int k=j+1;k<q[i].y.size();k++)hy[k]=(hy[k-1]+pw[k-j]*q[i].y[k]);
			for(int k=1;k<=n;k++){
				if(p[k].x.size()+j-1>=q[i].x.size())continue;
				if(Hx(j,j+p[k].x.size()-1)==ha[k]){
					if(Hy(j,j+p[k].x.size()-1)==hb[k]){
						res+=(Hx(j+p[k].x.size(),q[i].x.size()-1)==Hy(j+p[k].y.size(),q[i].y.size()-1));
					}
				}
			}
			hx[j]=hy[j]=0;
			if(q[i].x[j]!=q[i].y[j])break;
		}
		
		printf("%d\n",res);
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	int s1=0,s2=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
		len=max(len,(int)p[i].x.size());
		s1+=p[i].x.size();
		p[i].id=i;
	}
	for(int i=1;i<=m;i++){
		cin>>q[i].x>>q[i].y;
		s2+=q[i].x.size();
		q[i].id=i;
		len=max(len,(int)q[i].x.size());
	}
	if(s1<=2000&&s2<=2000)solve2();
	else if(check())solve1();
	
}