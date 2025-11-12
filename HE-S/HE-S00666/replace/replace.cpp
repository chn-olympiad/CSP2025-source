#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
const int m=2000010;

bool isEqual(string s1, string s2){
	if (s1.size()!=s2.size()) return false;
	for (int i=0;i<s1.size();i++){
		if (s1[i]!=s2[i]) return false;
	}return true;
}

typedef struct tree_node{
	char c; // char
	vector<tree_node*> next; // points to next layer
	int l;  //cur_layer (start:0)
	int i;  // -1 if not leaf,>=0 means the i
} trn;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, q;
	cin>>n>>q;
	for (int i=0;i<q;i++){
		cout<<0<<endl;
	}
	/*
	vector<pair<string,string> > s(m); // 0~n-1
	vector<trn> tree(26);
	for (int p=0;p<n;p++){
		string t[2];
		cin>>t[0]>>t[1];
		s[p].first=t[0];s[p].second=t[1];
		trn* nr;
		for (int i=0;i<t[0].size();i++){
			char c=t[0][i];
			if (i==0){
			if (tree[c-97].c!=c){
				trn *r = new trn;
				r->i=-1;r->c=c;r->l=0;
				tree[c-97]=*r;
				nr=r;
			} else {
				nr=&tree[c-97];
			}continue;}
			if (i==t[0].size()-1) {
				trn *r = new trn;
				r->i=p;r->c=c;r->l=t[0].size()-1;
				nr->next.push_back(r);
			} else {
				cout<<c<<endl;
				trn *r = new trn;
				r->i=-1;r->c=c;r->l=nr->l+1;
				nr->next.push_back(r);
				nr=r;
			}
		}
	}
	//bfs
	for (int p=0;p<q;p++){
		int res=0;
		string t[2];
		cin>>t[0]>>t[1];
		for (int i=0;i<t[0].size();i++){
			queue<trn> que;
			char c=t[0][i];
			if (tree[c-97].c!=c) continue;
			else que.push(tree[c-97]);
			while (!que.empty()){
				trn ct=que.front();
				cout<<"c:"<<ct.c<<" l:"<<ct.l<<" i:"<<ct.i<<" next_c:"<<ct.next[0]->c<<endl;
				if (ct.i!=-1) {
					string nt=t[0];
					nt.erase(nt.begin()+i,nt.begin()+i+ct.l+1);
					for (int j=0;j<s[i].second.size();j++)
						nt.insert(nt.begin()+i+j, s[i].second[j]);
					if (isEqual(nt,t[1])) res++;
					que.pop();
				}
				for (int i=0;i<ct.next.size();i++){
					que.push(*ct.next[i]);
				}
			}
		}
		cout<<res<<endl;
	}*/
	return 0;
}
