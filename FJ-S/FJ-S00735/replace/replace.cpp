#include<bits/stdc++.h>
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
const int Maxzfj=26;
const int N=2e5+10;
struct Node{
	int c1,c2;
	int son[Maxzfj][Maxzfj],fail;
};
Node t[N];
struct Need{
	int i,fa;
}tmp;
int n,q,cnt;
string s1,s2;
void make_fail(){
	queue<Need> q;
	tmp.fa=0;
	tmp.i=1;
	q.push(tmp);
	while(!q.empty()){
		Need i=q.front();
		q.pop();
		while(i.fa&&t[t[i.fa].fail].son[t[i.i].c1][t[i.i].c2]==0){
			i.fa=t[i.fa].fail;
		}
		t[i.i].fail=t[t[i.fa].fail].son[t[i.i].c1][t[i.i].c2];
		tmp.fa=i.i;
		for(int j=0;j<Maxzfj;j++){
			for(int k=0;k<Maxzfj;k++){
				if(t[i.i].son[j][k]!=0){
					tmp.i=t[i.i].son[j][k];
					q.push(tmp);
				}
			}
		}
	}
}
int main(){
	FILE("replace");
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	cnt=1;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int j=0,l=s1.length();
		int k=1;
		while(j<l){
			if(t[k].son[s1[j]-'a'][s2[j]-'a']==0){
				t[k].son[s1[j]-'a'][s2[j]-'a']=++cnt;
			}
			k=t[k].son[s1[j]-'a'][s2[j]-'a'];
			t[k].c1=s1[j]-'a';
			t[k].c2=s2[j]-'a';
			j++;
		}
	}
	make_fail();
	for(int i=1;i<q;i++){
		cout<<0;
	}
	return 0;
}
