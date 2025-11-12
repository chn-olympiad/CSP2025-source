#include<bits/stdc++.h>
#define ll long long
const ll INF=1e9+10,MAXN=5e6+10;
using namespace std;
int n,q,tot,t;
string a,b,a1,b1;
int tree[MAXN][30],ex[MAXN];
struct node{
	int l,r;
}fri[30][30];
vector<int>G[MAXN]; 
int get(char x){
	return x-'a';
}
void build(string a){
	int las=0;
	for(int i=0;i<a.size();i++){
		if(!tree[las][get(a[i])])tree[las][get(a[i])]=++tot;
		las=tree[las][get(a[i])];
		G[t].push_back(las);
	}
	ex[las]++;
	return;
}
int query(string a,string b){
	int t1=fri[get(a[1])][get(b[1])].l,t2=fri[get(a[1])][get(b[1])].r;
	if(t1==0)return 0;
	int las=0,lbs=0,l=0;
	for(int i=0;i<a.size();i++){
		if(!tree[las][get(a[i])])return 0;
		if(!tree[lbs][get(b[i])])return 0;
		las=tree[las][get(a[i])];
		lbs=tree[lbs][get(b[i])];
		if(G[t1][l]!=las)return 0;
		if(G[t2][l]!=lbs)return 0;
		l++;
	}
	return ex[las];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a1>>b1;
		a=b="";
		for(int i=0;i<a1.size();i++){
			if(a1[i]!=b1[i]){
				a+=a1[i];
				b+=b1[i];
			}
		}
		++t;
		build(a);
		fri[get(a[1])][get(b[1])].l=t;
		++t;
		build(b);
		fri[get(a[1])][get(b[1])].r=t;
	}
//	for(int i=1;i<=tot;i++)cout<<i<<" "<<ex[i]<<"\n";
	while(q--){
		cin>>a1>>b1;
		a=b="";
		for(int i=0;i<a1.size();i++){
			if(a1[i]!=b1[i]){
				a+=a1[i];
				b+=b1[i];
			}
		}
		cout<<query(a,b)<<"\n";
	}
	return 0;
}

