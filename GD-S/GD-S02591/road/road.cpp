#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std; 
int n,m,k; 
#define int long long
vector<pair<int,pair<int,int> > > egvec;
vector<pair<int,pair<int,int> > > egvec2[20];
vector<pair<int,pair<int,int> > > egvec3;
int chefei[20];

int mgst[15000];
void INIt(){
	for(int i=0;i<=13000;i++)mgst[i]=i;
}

int fa(int x){
	if(mgst[x]==x)return x;
	mgst[x]=fa(mgst[x]);
	return mgst[x];
}

bool merge(int x,int y){
	x=fa(x);y=fa(y);
	if(x==y)return false;
	mgst[x]=y;
	return true;
}

int kru2(){
	INIt();
	int ans=0;
	for(auto iter=egvec3.begin();iter!=egvec3.end();advance(iter,1)){
		int wt=iter->first;
		int u=iter->second.first;
		int v=iter->second.second;
		bool flag=merge(u,v);
		if(flag)ans+=wt;
	}
	return ans;
}

int kru(){
	INIt();
	int ans=0;
	for(auto iter=egvec.begin();iter!=egvec.end();advance(iter,1)){
		int wt=iter->first;
		int u=iter->second.first;
		int v=iter->second.second;
		bool flag=merge(u,v);
		if(flag)ans+=wt;
	}
	return ans;
}

int kru3(){
	INIt();
	int ans=0;
	int i=0;int j=0;
	int ss=egvec3.size();
	for(;i<m || j<ss;){
		pair<int,pair<int,int> > tege;
		if(i==m)tege=egvec3[j],j++;
		else if(j==ss){
			tege=egvec[i],i++;
		}
		else{
			if(egvec[i]<egvec3[j]){
				tege=egvec[i],i++;
			}
			else{
				tege=egvec3[j],j++;
			}
		}
		//cerr<<tege.first<<endl;
		int wt=tege.first;
		int u=tege.second.first;
		int v=tege.second.second;
		bool flag=merge(u,v);
		if(flag)ans+=wt;
	}
	return ans;
}

int Fread(){
	char ch=getchar();
	int x=0,f=1;
	while('0'>ch || ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch && ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=Fread();m=Fread();k=Fread();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=Fread();v=Fread();w=Fread();
		if(k!=0)egvec.push_back(make_pair(w,make_pair(u,v)));
		else egvec3.push_back(make_pair(w,make_pair(u,v)));
	}
	bool flag=true;
	for(int j=1;j<=k;j++){
		chefei[j]=Fread();
		if(chefei[j]!=0)flag=false;
		for(int i=1;i<=n;i++){
			int f;f=Fread();
			egvec2[j].push_back(make_pair(f,make_pair(i,j+12000)));
		}
	}
	if(k==0){
		sort(egvec3.begin(),egvec3.end());
		cout<<kru2()<<endl;return 0;
	}
	if(flag){
		for(int j=1;j<=k;j++){
			for(auto b:egvec2[j]){
				egvec3.push_back(b);
			}
		}
		for(auto iter=egvec.begin();iter!=egvec.end();advance(iter,1)){
			egvec3.push_back(*iter);
		}
		sort(egvec3.begin(),egvec3.end());
		cout<<kru2()<<endl;return 0;
	}
	sort(egvec.begin(),egvec.end());
	for(int i=1;i<=k;i++){
		sort(egvec2[i].begin(),egvec2[i].end());
	}
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int op=0;op<=(1<<k)-1;op++){
		egvec3.clear();
		for(int i=1;i<=k;i++){
			if(op&((1<<(i-1)))){
				for(auto eg:egvec2[i]){
					egvec3.push_back(eg); 
				}
			}
		}
		sort(egvec3.begin(),egvec3.end());
		int tt=0;
		for(int j=1;j<=k;j++){
			if(op&(1<<(j-1))){
				tt+=chefei[j];
			}
		}
		int xx=kru3();
		//cerr<<op<<' '<<xx<<endl;
		ans=min(ans,tt+xx);
	}
	cout<<ans<<endl;
	return 0;
}
