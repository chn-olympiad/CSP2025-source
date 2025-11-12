#include<bits/stdc++.h>
using namespace std;
int ta[5000001][26],tb[5000001][26],tra,trb;
vector<int> spa[5000001],spb[5000001];
int fa[5000001],fb[5000001];
int siz[200001];
void insert1(string s,int x){
	siz[x]=s.size();
	int p=0;
	for(int i=0;i<s.size();i++){
		if(!ta[p][s[i]-'a']) ta[p][s[i]-'a']=++tra;
		p=ta[p][s[i]-'a'];
	}
	spa[p].push_back(x);
}
void insert2(string s,int x){
	int p=0;
	for(int i=0;i<s.size();i++){
		if(!tb[p][s[i]-'a']) tb[p][s[i]-'a']=++trb;
		p=tb[p][s[i]-'a'];
	}
	spb[p].push_back(x);
}
void get_fail(){
	int p=0;
	queue<int> q1,q2;
	for(int i=0;i<26;i++){
		fa[ta[p][i]]=p;
		fb[tb[p][i]]=p;
		if(ta[p][i]) q1.push(ta[p][i]);
		if(tb[p][i]) q2.push(tb[p][i]);
	}
	while(!q1.empty()){
		p=q1.front();
		q1.pop();
		for(int i=0;i<26;i++){
			if(ta[p][i]) fa[ta[p][i]]=ta[fa[p]][i],q1.push(ta[p][i]);
			else ta[p][i]=ta[fa[p]][i];
		}
	}
	while(!q2.empty()){
		p=q2.front();
		q2.pop();
		for(int i=0;i<26;i++){
			if(tb[p][i]) fb[tb[p][i]]=tb[fb[p]][i],q2.push(tb[p][i]);
			else tb[p][i]=tb[fb[p]][i];
		}
	}
}
char sxi[5000001],syi[5000001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		scanf("%s%s",sxi,syi);
		insert1(sxi,i);
		insert2(syi,i);
	}
	get_fail();
	for(int i=1;i<=q;i++){
		scanf("%s%s",sxi,syi);
		string sx=sxi,sy=syi;
		int l=-1,r=-1;
		for(int j=0;j<sx.size();j++) if(sx[j]!=sy[j]) {l=j;break;}
		for(int j=sx.size()-1;j>=0;j--) if(sx[j]!=sy[j]) {r=j;break;}
		int pa=0,pb=0,s=0;
		for(int j=0;j<r;j++) pa=ta[pa][sx[j]-'a'],pb=tb[pb][sy[j]-'a'];
		for(int j=r;j<sx.size();j++){
			set<int> sp;
			pa=ta[pa][sx[j]-'a'];
			pb=tb[pb][sy[j]-'a'];
			for(int t=pa;t;t=fa[t]){
				for(auto g:spa[t]) if(siz[g]>j-l) sp.insert(g);
			}
			for(int t=pb;t;t=fb[t]){
				for(auto g:spb[t]){
					if(sp.count(g)) s++;
				}
			}
		}
		cout<<s<<endl;
	}
	
	return 0;
}
