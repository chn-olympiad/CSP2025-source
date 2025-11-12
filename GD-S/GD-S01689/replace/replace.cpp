#include<bits/stdc++.h>
using namespace std;
char get_char;
bool sign;
bool isnum(const char &x){
	return ('0'<=x && x<='9');
}
void read(int &x){
	x=0;
	get_char=getchar();
	sign=0; 
	while(!isnum(get_char)){
		if(get_char=='-')sign=1;
		get_char=getchar();
	}
	while(isnum(get_char)){
		x=(x<<3)+(x<<1)+(get_char-'0');
		get_char=getchar();
	}
	if(sign)x=-x;
}
struct node{
	node *c[30];
};
struct Tree{
	node *root=new node,*it;
	int i;
	void insert(const string &x){
		it=root;
		i=0;
		while(i<x.size()){
			if(it->c[x[i]-'a']==NULL)it->c[x[i]-'a']=new node;
			it=it->c[x[i]-'a'];
			i++;
		}
	}
	bool find(const string &x){
		it=root;
		i=0;
		while(i<x.size()){
			if(it->c[x[i]-'a']==NULL)return 1;
			it=it->c[x[i]-'a'];
			i++;
		}
		return 0;
	}
}tree;
int n,q;
const int N=2e5+5;
string x,y,z,aaa;
map<string,string>S;
int cnt;
int query(){
	cnt=0;
	for(int i=0,j;i<x.size();i++){
		for(j=i;j<x.size();j++){
			z="";
			for(int iii=i;iii<=j;iii++){
				z+=x[iii];
			}
			if(!S.count(z))continue;
			aaa=x;
			for(int iii=i;iii<=j;iii++)aaa[iii]=S[z][iii-i];
			if(y==aaa)cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);read(q);
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		S[x]=y;
		tree.insert(x);
	}
	while(q--){
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<"0\n";
			continue;
		}
		cout<<query()<<'\n';
	}
	return 0;
}
