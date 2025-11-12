#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=5e6+5;
bool FIRST;
string S1[N<<1],S2[N<<1];
int n,Q,Siz[N];
string s1,s2;
struct tree{
	int son[26],fail;
	vector<int>sum;
};
queue<int>q;
struct AC_{
	tree f[M];
	int cnt=0;
	int newnode(){
		f[++cnt].fail=0;
		memset(f[cnt].son,0,sizeof f[cnt].son);
		f[cnt].sum.clear();
		return cnt;
	}
	void Insert(string s,int id){
		int now=0;
		for(int i=0;i<s.size();i++){
			if(!f[now].son[s[i]-'a'])f[now].son[s[i]-'a']=newnode();
			now=f[now].son[s[i]-'a'];
		}
		f[now].sum.push_back(id);
	}
	void getfail(){
		while(!q.empty())q.pop();
		for(int i=0;i<26;i++)if(f[0].son[i])q.push(f[0].son[i]);
		while(!q.empty()){
			int now=q.front();q.pop();
			for(int i=0;i<26;i++){
				if(!f[now].son[i])f[now].son[i]=f[f[now].fail].son[i];
				else f[f[now].son[i]].fail=f[f[now].fail].son[i],q.push(f[now].son[i]);
			}
		}
		return ;
	}
}AC1,AC2;
int v1[N],v2[N],cnt1,cnt2;
int vis[M];
ll Vis[N];
bool check(string s){
	int flag=false;
	for(int i=0;i<s.size();i++){
		if(s[i]=='a');
		else if(s[i]=='b'){
			if(flag)return false;
			flag=true;
		}else return false;
	}
	if(!flag)return false;
	return true;
}
struct ques{
	int a,b,id;
}a[N],b[N];
bool cmp(ques a,ques b){
	if(a.b-a.a==b.b-b.a){
		if(a.a==b.a)return a.b<b.b;
		return a.a<b.a;
	}
	return a.b-a.a<b.b-b.a;
}
int Ans[N];
struct Tree{
	int sum,tag;
}F[M<<2];
#define ls id<<1
#define rs id<<1|1
void pushdown(int id){
	if(F[id].tag){
		F[ls].sum=F[rs].sum=0;
		F[ls].tag=F[rs].tag=1;
		F[id].tag=0;
	}
	return ;
}
void pushup(int id){
	F[id].sum=F[ls].sum+F[rs].sum;
	return ;
}
void update(int id,int l,int r,int x,int y){
	if(l==r){
		F[id].sum+=y;
		return ;
	}
	int mid=(l+r)/2;
	pushdown(id);
	if(x<=mid)update(ls,l,mid,x,y);
	else update(rs,mid+1,r,x,y);
	pushup(id);
	return ;
}
int query(int id,int l,int r,int x,int y){
	if(l>=x&&r<=y)return F[id].sum;
	int mid=(l+r)/2,ANS=0;
	pushdown(id);
	if(x<=mid)ANS+=query(ls,l,mid,x,y);
	if(y>=mid+1)ANS+=query(rs,mid+1,r,x,y);
	return ANS;
}
bool SECOND;
int main(){
//	cout<<(double)((&FIRST-&SECOND)/1024.0/1024.0)<<"MB";return 0;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>Q;
	bool flag=true;
	for(int i=1;i<=n+Q;i++){
		cin>>S1[i]>>S2[i];
		flag&=check(S1[i]);
		flag&=check(S2[i]);
	}
	if(flag){
		int maxl=0;
		for(int i=1;i<=n+Q;i++){
			int SIZ1=S1[i].size(),SIZ2=S2[i].size();
			maxl=max(maxl,max(SIZ1,SIZ2));
			S1[i]=" "+S1[i];
			S2[i]=" "+S2[i];
		}
		for(int i=1;i<=n;i++){
			int pos1=0,pos2=0;
			for(int j=1;j<S1[i].size();j++){
				if(S1[i][j]=='b')pos1=j;
				if(S2[i][j]=='b')pos2=j;
			}
			a[i]=(ques){pos1,pos2,i};
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=Q;i++){
			int pos1=0,pos2=0;
			for(int j=1;j<S1[n+i].size();j++){
				if(S1[n+i][j]=='b')pos1=j;
				if(S2[n+i][j]=='b')pos2=j;
			}
			b[i]=(ques){pos1,pos2,i};
		}
		sort(b+1,b+Q+1,cmp);
		int Cnt=1;
//		cout<<maxl<<":\n";
//		for(int i=1;i<=n;i++)cout<<a[i].a<<" "<<a[i].b<<"\n";cout<<"\n";
//		for(int i=1;i<=Q;i++)cout<<b[i].a<<" "<<b[i].b<<"\n";cout<<"\n";
		for(int i=1;i<=Q;i++){
			if(S1[b[i].id+n].size()!=S2[b[i].id+n].size())continue;
			if(i==1||b[i].b-b[i].a!=b[i-1].b-b[i-1].a)F[1].tag=1;//,cout<<"Clear\n";
			while(Cnt<=n&&a[Cnt].b-a[Cnt].a<b[i].b-b[i].a)Cnt++;
			while(Cnt<=n&&a[Cnt].b-a[Cnt].a==b[i].b-b[i].a&&a[Cnt].a<=b[i].a){
//				cout<<a[Cnt].a<<" "<<a[Cnt].b<<"\n";
				update(1,1,maxl,S1[a[Cnt].id].size()-a[Cnt].b+1,1);Cnt++;
			}
			Ans[b[i].id]=query(1,1,maxl,1,S1[b[i].id+n].size()-b[i].b+1);
//			cout<<b[i].a<<" "<<b[i].b<<": "<<Ans[b[i].id]<<"\n";
		}
		for(int i=1;i<=Q;i++)cout<<Ans[i]<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		s1=S1[i],s2=S2[i];
		if(s1.size()!=s2.size())continue;
		Siz[i]=s1.size();
		AC1.Insert(s1,i);
		AC2.Insert(s2,i);
	}
	AC1.getfail();
	AC2.getfail();
	for(int qq=1;qq<=Q;qq++){
		s1=S1[n+qq];s2=S2[n+qq];
		if(s1.size()!=s2.size()){
			cout<<0<<"\n";
			continue;
		}
		int fi=-1,se=-1;
		for(int i=0;i<s1.size();i++)if(s1[i]!=s2[i]){if(fi==-1)fi=i;se=i;}
		int now1=0,now2=0,ans=0;cnt1=cnt2=0;
		vis[0]=qq;
		for(int i=0;i<s1.size();i++){
			now1=AC1.f[now1].son[s1[i]-'a'];
			now2=AC2.f[now2].son[s2[i]-'a'];
			if(i<se)continue;
			for(int j=now1;vis[j]!=qq;j=AC1.f[j].fail){
				for(int k=0;k<AC1.f[j].sum.size()&&i-Siz[AC1.f[j].sum[k]]+1<=fi;k++){
					if(Vis[AC1.f[j].sum[k]]==1ll*qq*M+i)ans++;
					Vis[AC1.f[j].sum[k]]=1ll*qq*M+i;
				}
			}
			for(int j=now2;vis[j]!=qq;j=AC2.f[j].fail){
				for(int k=0;k<AC2.f[j].sum.size()&&i-Siz[AC2.f[j].sum[k]]+1<=fi;k++){
					if(Vis[AC2.f[j].sum[k]]==1ll*qq*M+i)ans++;
					Vis[AC2.f[j].sum[k]]=1ll*qq*M+i;
				}
			}
		}
//		for(int i=1;i<=n;i++)if(Vis[i]==qq)cout<<S1[i]<<"-->"<<S2[i]<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}
