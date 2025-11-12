#include<bits/stdc++.h>
using namespace std;
struct tree{
	vector<string> s;
	tree *nx[26]={},*it=NULL;
}*top=new tree;
void add(string s1,string s2){
	tree *p=top;
	for(char i:s1){
		if(p->nx[i-'a']==NULL){
			p->nx[i-'a']=new tree;
		}p=p->nx[i-'a'];
	}p->s.push_back(s2);
}void ac(){
	top->it=top;
	queue<tree*> q;
	q.push(top);
	while(q.size()){
		tree *t=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			if(t->nx[i]==NULL)continue;
			tree *p=t->it;
			while(1){
				if(p->nx[i]!=NULL && p->nx[i]!=t->nx[i]){
					t->nx[i]->it=p->nx[i];
					break;
				}if(p==top){
					t->nx[i]->it=top;
					break;
				}p=p->it;
			}q.push(t->nx[i]);
		}
	}
}int query(string s1,string s2){
	int cnti=0;
	tree *t=top;
	string sr=s1;
	for(int i=0;i<s1.size();i++){
		sr=sr.substr(1);
		while(t!=top && t->nx[s1[i]-'a']==NULL){
			t=t->it;
		}if(t->nx[s1[i]-'a']!=NULL){
			t=t->nx[s1[i]-'a'];
		}tree *p=t;
		string sl="";
		while(p!=top){
			if(p->s.size()!=0){
				for(string s:p->s){
					while(sl.size()+s.size()<=i){
						sl+=s1[sl.size()];
					}if(sl+s+sr==s2){
						cnti++;
					}
				}
			}p=p->it;
		}
	}return cnti;
}
int n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		add(x,y);
	}ac();
	for(int i=1;i<=m;i++){
		string x,y;
		cin>>x>>y;
		cout<<query(x,y)<<"\n";
	}
	return 0;
} 
