#include<bits/stdc++.h>
using namespace std;
int n,k,b[500010],kjg,ans;
vector<int> a[500010];
vector<int> qz[500010];
vector<int> kk;
struct node{
	int e,s;
}jg[500010];
bool px(node x,node y){
	if(x.s==y.s) return x.e<y.e;
	return x.s<y.s;
}
void cf(int x){
	int t=1;
	while(b[x]){
		if(b[x]%2==1) a[x].push_back(t);
		b[x]/=2;
		t++;
	}
}
vector<int> hb(vector<int> x,vector<int> y){
	vector<int> z;
	int c[30];
	for(int i=1;i<=20;i++) c[i]=0;
	for(int i=0;i<x.size();i++) c[x[i]]++;
	for(int i=0;i<y.size();i++) c[y[i]]++;
	for(int i=1;i<=20;i++) if(c[i]%2==1) z.push_back(i);
	return z;
}
bool pd(vector<int> x){
	if(x.size()!=kk.size()) return 0;
	for(int i=0;i<x.size();i++) if(x[i]!=kk[i]) return 0;
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cf(i);
	int t=1;
	while(k){
		if(k%2==1) kk.push_back(t);
		k/=2;
		t++;
	}
	int c[30];
	for(int i=0;i<a[1].size();i++) qz[1].push_back(a[1][i]);
	for(int i=2;i<=n;i++){
		for(int j=1;j<=20;j++) c[j]=0;
		for(int j=0;j<a[i].size();j++) c[a[i][j]]++;
		for(int j=0;j<qz[i-1].size();j++) c[qz[i-1][j]]++;
		for(int j=1;j<=20;j++) if(c[j]%2==1) qz[i].push_back(j);
	}
	for(int i=1;i<=n;i++){
		if(pd(qz[i])){
			kjg++;
			jg[kjg].e=1;
			jg[kjg].s=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(pd(hb(qz[i],qz[j]))){
				kjg++;
				jg[kjg].e=j+1;
				jg[kjg].s=i;
			}
		}
	}
	sort(jg+1,jg+1+kjg,px);
	int de=jg[1].s;
	ans=1;
	for(int i=2;i<=kjg;i++){
		if(jg[i].e>de){
			de=jg[i].s;
			ans++;
		}
	}
	if(kjg==0){
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}

