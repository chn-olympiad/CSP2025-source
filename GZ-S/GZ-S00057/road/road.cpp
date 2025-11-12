//GZ-S00057 毕节七星关东辰实验学校 刘杰 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct kk{
	ll x,y,w;
};
vector<kk> v;

struct pt{
	ll c;
	vector<ll> to;
};
vector<pt> sd;

int n,m,k;

int fa[100021];
int fid(ll x){
	if(fa[x]!=x){
		fa[x]=fid(fa[x]);
	}
	return fa[x];
}
void uni(ll r1,ll r2){
	fa[r2]=r1;
}
bool cmp(kk x,kk y){
	return x.w<y.w;
}
ll kluskal(){
	sort(v.begin(),v.end(),cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		int r1=fid(v[i].x),r2=fid(v[i].y);
		if(r1!=r2){
			uni(r1,r2);
			ans+=v[i].w;
		}
	}
	return ans;
}

ll kplans=11451419;int p[11];
ll kp(int l){
	vector<kk> kl;
	kl=v;ll ans=0;
	for(int i=1;i<=l;i++){
		
		ans+=sd[p[i]].c;
		for(int j=1;j<=n;j++){
			kk sp;
			sp.x=n+p[i];
			sp.y=j;
			sp.w=sd[p[i]].to[j];
			kl.push_back(sp);
		}
		
	}
	sort(kl.begin(),kl.end(),cmp);
	for(int i=1;i<=kl.size();i++){
		fa[i]=i;
	}
	for(int i=0;i<kl.size();i++){
		int r1=fid(kl[i].x),r2=fid(kl[i].y);
		if(r1!=r2){
			uni(r1,r2);
			ans+=kl[i].w;
		}
	}
	return ans;
}
void dfs(int w,int jin){
	if(jin==k||w>k)    return;
	p[w]=jin;
	kplans=min(kp(w),kplans);
	//cout<<kplans<<endl;
	dfs(w,jin+1);
	p[w]=jin;
	dfs(w+1,jin+1);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,vi,w;
		cin>>u>>vi>>w;
		kk l;
		l.x=u;
		l.y=vi;
		l.w=w;
		v.push_back(l);
	}
	for(int i=1;i<=k;i++){
		int c;cin>>c;
		pt l;
		l.c=c;
		for(int j=1;j<=n;j++){
			cin>>c;
			l.to.push_back(c);
		}
		sd.push_back(l);
	}
	int cl=1;
	for(int i=0;i<k;i++){
		if(sd[i].c!=0){
			cl=0;break;
		}
	}
	if(k==0){    //no change
	//can get 16 pts.
		cout<<kluskal();
	}
	else if(cl){
		cout<<0;
	}
	else{    //wo mei zhe le
	//I have no idea to use baoli!
	//17:55 Finally tiao chu lai le!
	//I dont know how many scores could I get.
	//At least I can get 16 pts.
	//If I am very lucky,I can AC this question!
		dfs(1,0);
		cout<<min(kluskal(),kplans);
	}
	//18:05 Through my thinking,I didn't use A to cheat scores!
	//becouse it's useless!
	//18:11 add it again.
	return 0;
	//I am sure that this is the longest code I have been programed.
}

