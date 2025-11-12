#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=5500005;
const int base=38303,Mod=998244353;
int n,q;
char s1[M],s2[M];
int tot;
int cnt1,cnt2;
void read(){
	tot=0;
	char c;
	while(c=getchar(),c!=' '){
		s1[tot++]=c;
	}
	for(int i=0;i<tot;i++){
		s2[i]=getchar();
	}
	getchar();
	for(cnt1=0;s1[cnt1]==s2[cnt1]&&cnt1<tot;cnt1++);
	for(cnt2=0;s1[tot-cnt2-1]==s2[tot-cnt2-1]&&cnt2<tot;cnt2++);
}
int son1[M][26],val1[M],tot1;
int nxt1[N];
void add1(int k,int now,int ed,int id){
	if(now>ed){
		if(val1[k]){
			nxt1[id]=val1[k];
		}
		val1[k]=id;
		return;
	}
	int s=s1[now]-'a';
	if(!son1[k][s])son1[k][s]=++tot1;
	add1(son1[k][s],now+1,ed,id);
}
int vis[N];
void check(int k,int now,int ed){
	if(val1[k]){
		int t=val1[k];
		while(t){
			vis[t]=!vis[t];
			t=nxt1[t];
		}
	}
	if(now>ed){
		return;
	}
	int s=s1[now]-'a';
	check(son1[k][s],now+1,ed);
}
int son2[M][26],val2[M],tot2;
int nxt2[N];
void add2(int k,int now,int ed,int id){
	// cout<<k<<" "<<now<<" "<<ed<<" "<<id<<"\n";
	if(now<ed){
		// cout<<"("<<k<<" "<<id<<")";
		if(val2[k]){
			nxt2[id]=val2[k];
		}
		val2[k]=id;
		return;
	}
	int s=s1[now]-'a';
	if(!son2[k][s])son2[k][s]=++tot2;
	add2(son2[k][s],now-1,ed,id);
}
int getans(int k,int now,int ed){
	int v=0;
	if(val2[k]){
		int t=val2[k];
		while(t){
			v+=vis[t];
			t=nxt2[t];
		}
	}
	// cout<<k<<" "<<val2[k]<<" "<<vis[val2[k]]<<"\n";
	// cout<<k<<" "<<now<<" "<<ed<<"("<<val2[k]<<"\n";
	if(now<ed){
		return v;
	}
	int s=s1[now]-'a';
	return getans(son2[k][s],now-1,ed)+v;
}
int gethash(){
	long long ky=0;
	for(int i=cnt1;i<tot-cnt2;i++){
		ky=(ky*base%Mod+s1[i])%Mod;
		ky=(ky*base%Mod+s2[i])%Mod;
		// cout<<s1[i]<<" ";
	}
	// cout<<"\n";
	// cout<<"("<<ky<<"\n";
	// ky=(ky*base%Mod+tot)%Mod;
	return ky;
}
int TOT=5500000;
map<int,int>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	getchar();
	int TAT=0;
	for(int i=1;i<=n;i++){
		read();
		int hsh=gethash();
		if(!mp[hsh])mp[hsh]=TOT--;
		int root=mp[hsh];
		add1(root,tot-cnt2,tot-1,i);
		add2(root,cnt1-1,0,i);
	}
	while(q--){
		read();
		int id=mp[gethash()];
		check(id,tot-cnt2,tot-1);
		cout<<getans(id,cnt1-1,0)<<"\n";
		check(id,tot-cnt2,tot-1);
	}
	return 0;
}