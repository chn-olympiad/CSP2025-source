//GZ-S00344 贵阳市第一中学 甘梓辰
#include<bits/stdc++.h>
using namespace std;
int n,m,ans[200005],son[5000005][26],v[5000005],tot;
string s[400005][2],t[200005][2];
struct node{
	int id,len,h,v,l,r,op;
}q[400005],a[200005];
bool cmp(node a,node b){
	if(a.v==b.v&&a.h==b.h){
		return a.op<b.op;
	}
	return a.v==b.v?a.h<b.h:a.v<b.v;
}
const int mod=1e9+3,B=127;
vector<int> h[400005];
int st[200005],top;
void erase(int x){
	int u=1;
	for(int i=a[x].r+1;i<a[x].len;i++){
		u=son[u][s[a[x].id][0][i]-'a'];
	}
	v[u]--;
}
void insert(int x){
	int u=1;
	for(int i=a[x].r+1;i<a[x].len;i++){
		int v2=son[u][s[a[x].id][0][i]-'a'];
		if(!v2){
			son[u][s[a[x].id][0][i]-'a']=++tot;
			for(int j=0;j<26;j++){
				son[tot][j]=0;
			}
			v[tot]=0;
		}
		u=son[u][s[a[x].id][0][i]-'a'];
	}
	v[u]++;
}
int gs(int x){
	int u=1,sum=0;
	for(int i=a[x].r+1;i<a[x].len;i++){
		sum+=v[u];
		int v=son[u][s[a[x].id][0][i]-'a'];
		if(!v){
			return sum;
		}
		u=v;
	}
	sum+=v[u];
	return sum;
}
void solve(int l,int r){
//	cout<<l<<" "<<r<<" "<<s[a[l].id][0]<<endl;
	top=0;
	for(int i=0;i<26;i++){
		son[1][i]=0;
	}
	tot=1;
	v[1]=0;
	for(int i=l;i<=r;i++){
		while(top&&(a[st[top]].l>a[i].l||h[a[st[top]].id][a[st[top]].l]!=h[a[i].id][a[st[top]].l])){
			erase(st[top]);
			top--;
		}
		if(a[i].op==0){
			ans[a[i].id-n]=gs(i);
		}else{
			insert(i);
		}
	}
	return ;
}
void sorta(int l,int r,int dep){
//	cout<<l<<" "<<r<<'\n';
	if(l>r){
		return ;
	}
	if(dep==-1){
		int pl=1;
		for(int i=1;i<=r;i++){
			if(a[i].v!=a[i+1].v||a[i].h!=a[i+1].h){
				sorta(pl,i,0);
				solve(pl,i);
				pl=i+1;
			}
		}
		if(pl<=r){
			sorta(pl,r,0);
			solve(pl,r);
		}
		return ;
	}
	if(a[l].v==0){
		return ;
	}
	vector<node> p[27];
	for(int i=l;i<=r;i++){
		if(a[i].l-dep-1>=0){
			p[s[a[i].id][0][a[i].l-dep-1]-'a'+1].push_back(a[i]); 
		}else{
			p[0].push_back(a[i]);
		}
	}
	int pid=l,pl=l;
	for(int i=0;i<p[0].size();i++){
		a[pid]=p[0][i];
		pid++;
	}
	pl=pid;
	for(int k=1;k<=26;k++){
		for(int i=0;i<p[k].size();i++){
			a[pid]=p[k][i];
			pid++;
		}
		sorta(pl,pid-1,dep+1);
		pl=pid;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		a[i].id=i;
		a[i].len=s[i][0].size();
		a[i].l=1;
		for(int j=0;j<a[i].len;j++){
			if(s[i][0][j]!=s[i][1][j]){
				a[i].l=j;
				break;
			}
		}
		for(int j=a[i].len-1;j>=0;j--){
			if(s[i][0][j]!=s[i][1][j]){
				a[i].r=j;
				break;
			}
		}
		a[i].v=a[i].r-a[i].l+1;
		h[i].push_back(0);
		int k=0;
		for(int j=a[i].l-1;j>=0;j--){
			k=(k*1ll*127+s[i][0][j])%mod;
			h[i].push_back(k);
		}
		k=0;
		for(int j=a[i].l;j<=a[i].r;j++){
			k=(k*1ll*127+s[i][0][j])%mod;
			k=(k*1ll*127+s[i][1][j])%mod;
		}
		a[i].h=k;
		a[i].op=-1;
	}
	for(int i=1;i<=m;i++){
		cin>>s[i+n][0]>>s[i+n][1];
		a[i+n].id=i+n;
		a[i+n].len=s[i+n][0].size();
		if(s[i+n][0].size()!=s[i+n][1].size()){
			a[i+n].op=1;
		}else{
			a[i+n].l=1;
			for(int j=0;j<a[i+n].len;j++){
				if(s[i+n][0][j]!=s[i+n][1][j]){
					a[i+n].l=j;
					break;
				}
			}
			for(int j=a[i+n].len-1;j>=0;j--){
				if(s[i+n][0][j]!=s[i+n][1][j]){
					a[i+n].r=j;
					break;
				}
			}
			a[i+n].v=a[i+n].r-a[i+n].l+1;
			h[i+n].push_back(0);
			int k=0;
			for(int j=a[i+n].l-1;j>=0;j--){
				k=(k*1ll*127+s[i+n][0][j])%mod;
				h[i+n].push_back(k);
			}
			k=0;
			for(int j=a[i+n].l;j<=a[i+n].r;j++){
				k=(k*127+s[i+n][0][j])%mod;
				k=(k*127+s[i+n][1][j])%mod;
			}
			a[i+n].h=k;
		}
	}
	sort(a+1,a+n+m+1,cmp);
	sorta(1,n+m,-1);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}

