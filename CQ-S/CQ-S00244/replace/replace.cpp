#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	node *to[26],*fail;
	int dep,vis;
	vector<int> ed;
	node(){memset(to,0,sizeof(to));fail=NULL;dep=vis=0;}
}*head1=new node,*head2=new node;
int n,q;
string s1,s2;
void insert(node* head,string s,int i){
	for(char c:s)head=((head->to[c-'a']?head->to[c-'a']:head->to[c-'a']=new node),head->to[c-'a']->dep=head->dep+1,head->to[c-'a']);
	head->ed.push_back(i);
}
void build(node* head){
	head->fail=head;
	queue<node*> q;
	for(int i=0;i<26;i++){
		if(head->to[i])q.push(head->to[i]),head->to[i]->fail=head;
		else head->to[i]=head;
	}
	while(q.size()){
		node* u=q.front();
		q.pop();
		for(int i=0;i<26;i++)if(u->to[i])u->to[i]->fail=u->fail->to[i],q.push(u->to[i]);
		else u->to[i]=u->fail->to[i]; 
	}
}
int getans(string a,string b,int l,int r){
	node *u=head1,*v=head2;
	int re=0;
	for(int i=1;i<a.size();i++){
		u=u->to[a[i]-'a'];
		v=v->to[b[i]-'a'];
		if(i>=r){
			node *fl1=u,*fl2=v;
			while(i-min(fl1->dep,fl2->dep)+1<=l){
				if(fl1->dep<fl2->dep)swap(fl1,fl2);
				int ul=0;
				for(int i:fl1->ed){
					while(ul<fl2->ed.size()&&fl2->ed[ul]<i)ul++;
					if(ul!=fl2->ed.size()&&fl2->ed[ul]==i)re++;
				}
				fl1->vis=1;
				fl1=fl1->fail;
			}
		}
	}
	return re;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		insert(head1,s1,i);
		insert(head2,s2,i);
	}
	build(head1);
	build(head2);
	while(q--){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<'\n';
			continue;
		}
		s1=' '+s1;
		s2=' '+s2;
		int l=1,r;
		for(;s1[l]==s2[l];l++){}
		for(r=s1.size()-1;s1[r]==s2[r];r--){}
		cout<<getans(s1,s2,l,r)<<'\n';
	}
}

