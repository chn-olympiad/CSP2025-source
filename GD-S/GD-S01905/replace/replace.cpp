#include<bits/stdc++.h>
//#define int long long

using namespace std;

const int N=5e6+5;

int n,q,xdd=1,t[N],ne[N],num[N],dep[N],f[N][25];
vector<pair<int,int>> s[N];
string x,y;

int find(int o,int p){
	if(!s[o].size()||s[o][0].first>p) return 0;
	int lp=0,rp=s[o].size()-1,res,mid;
	while(lp<=rp){
		mid=lp+rp>>1;
		if(s[o][mid].first<=p) res=mid,lp=mid+1;
		else rp=mid-1;
	}
	if(s[o][res].first==p) return s[o][res].second;
	return 0;
}

void push(int o,int p){
	s[o].push_back({p,++xdd});
	for(int i=s[o].size()-1;i>=1;i--) if(s[o][i].first<s[o][i-1].first) swap(s[o][i],s[o][i-1]);
}

void insert(){
	int m=x.size();
	x=" "+x,y=" "+y;
	int o=1,de=0;
	for(int i=1;i<=m;i++){
		int p=(x[i]-'a')*26+y[i]-'a';
		if(!find(o,p)) push(o,p);
		o=find(o,p);
		dep[o]=++de;
//		cout<<o<<" ";
	}
//	cout<<"\n";
	num[o]++;
}

int que[N],ll,rr;

void build(){
	que[1]=ll=rr=1;
	while(ll<=rr){
		int o=que[ll++];
		num[o]+=num[ne[o]];
//		cout<<o<<" "<<ne[o]<<" "<<num[o]<<"\n";
		for(auto u:s[o]){
			int x=u.first,y=u.second;
			int pp=ne[o];
			while(!find(pp,x)) pp=ne[pp];//,cout<<pp<<" ";
			ne[y]=find(pp,x);
			que[++rr]=y;
		}
	}
}

int up(int o,int p){//找到最后一个深度<p的地方 
	if(dep[o]<p) return o;
	for(int i=23;i>=0;i--) if(dep[f[o][i]]>=p) o=f[o][i];
	return f[o][0];
}

void ask(){
	if(x.size()!=y.size()){
		cout<<"0\n";
		return;
	}
	int ans=0,o=1,m=x.size();
	x=" "+x,y=" "+y;
	int l=0,r=0;
	for(int i=1;i<=m;i++){
		if(x[i]!=y[i]){
			if(!l) l=i;
			r=i;
		}
	}
	if(!l&&!r){
		for(int i=1;i<=m;i++){
			int p=(x[i]-'a')*26+y[i]-'a';
			while(!find(o,p)) o=ne[o];
			o=find(o,p);
			ans+=num[o];
		}
		cout<<ans<<"\n";
		return;
	}
//	cout<<l<<" "<<r<<"\n";
	for(int i=1;i<=m;i++){
		int p=(x[i]-'a')*26+y[i]-'a';
		while(!find(o,p)) o=ne[o];
		o=find(o,p);
//		cout<<o<<" ";
		if(i>=r) ans+=num[o]-num[up(o,i-l+1)];//,cout<<o<<" "<<up(o,i-l+1)<<"hhh\n";
	}
//	cout<<"\n";
	cout<<ans<<"\n";
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	while(n--) cin>>x>>y,insert();
	for(int i=0;i<=25*26+25;i++) s[0].push_back({i,1});
	build();
	for(int i=0;i<=xdd;i++) f[i][0]=ne[i];
	for(int j=1;j<=23;j++) for(int i=0;i<=xdd;i++) f[i][j]=f[f[i][j-1]][j-1];
	while(q--) cin>>x>>y,ask();
}
