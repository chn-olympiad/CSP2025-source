#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
struct node{
	ll k[4],id;
}e[N];
struct nodea{
	ll val,id,m;
	bool operator >(const nodea &x)const {
		return x.val<val;
	}
};
struct nodeb{
	ll val,id,m;
	bool operator >(const nodeb &x)const {
		return x.val<val;
	}
};
struct nodec{
	ll val,id,m;
	bool operator >(const nodec &x)const {
		return x.val<val;
	}
};
ll T,n,a[N][4],cnta,cntb,cntc,ans;
bool cmp(node x,node y){
	if(a[x.id][x.k[1]]!=a[y.id][y.k[1]]) return a[x.id][x.k[1]]>a[y.id][y.k[1]];
	else if(a[x.id][x.k[2]]!=a[y.id][y.k[2]]) return a[x.id][x.k[2]]>a[y.id][y.k[2]];
	return a[x.id][x.k[3]]>a[x.id][x.k[3]];
}
priority_queue<nodea,vector<nodea>,greater<nodea>>qa;
priority_queue<nodeb,vector<nodeb>,greater<nodeb>>qb;
priority_queue<nodec,vector<nodec>,greater<nodea>>qc;
bool check(ll x,ll op,ll id,ll m){//op代表去a/b/c，id代表当前是第几个，x为权值 ,m处进来的 
	if(op==1){
		if(cnta<n/2){
			qa.push({x,id,m});
			cnta++;
			return true;
		}
		else {
			if(qa.top().val<x){
				qa.push({x,id,m});
				nodea t=qa.top();
				qa.pop();
				if(m<3) check({a[t.id][t.m+1],e[t.id].k[m+1],id,m+1});
			}
			else return false;
		}		
	}
	if(op==2){
		if(cntb<n/2){
			qb.push({x,id,m});
			cntb++;
			return true;
		}
		else {
			if(qb.top().val<x){
				qb.push({x,id,m});
				nodeb t=qb.top();
				qb.pop();
				if(m<3) check({a[t.id][t.m+1],e[t.id].k[m+1],id,m+1});
			}
			else return false;
		}		
	}
	if(op==3){
		if(cntc<n/2){
			qc.push({x,id,m});
			cntc++;
			return true;
		}
		else {
			if(qc.top().val<x){
				qc.push({x,id,m});
				nodea t=qc.top();
				qc.pop();
				if(m<3) check({a[t.id][t.m+1],e[t.id].k[m+1],id,m+1});
			}
			else return false;
		}		
	}
}
void solve(ll x){
	for(int i=1;i<=3;i++){
		if(e[x].k[i]==1)
			if(check(a[e[x].id][1],1,x,i)) return ;
		if(e[x].k[i]==2)
			if(check(a[e[i].id][2],2,x,i)) return ;
		if(e[x].k[i]==3)
			if(check(a[e[i].id][3],3,x,i)) return ;
	}
}
int main(){
	scanf("%lld",&T);
	while(T--){cnta=cntb=cntc=ans=0;
		while(!qa.empty) qa.pop();
		while(!qb.empty) qb.pop();
		while(!qc.empty) qc.pop();
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3]) e[i].k[1]=1,e[i].k[2]=2,e[i].k[3]=3;
			else if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2]) e[i].k[1]=1,e[i].k[2]=3,e[i].k[3]=2;
			else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3]) e[i].k[1]=2,e[i].k[2]=1,e[i].k[3]=3;
			else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1]) e[i].k[1]=2,e[i].k[2]=3,e[i].k[3]=1;
			else if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2]) e[i].k[1]=3,e[i].k[2]=1,e[i].k[3]=2;
			else if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1]) e[i].k[1]=3,e[i].k[2]=2,e[i].k[3]=1;
			e[i].id=i;
		}
		sort(e+1,e+1+n,cmp);
		for(ll i=1;i<=n;i++) solve(i);
		printf("%lld\n",ans);
	}
	return 0;
}
