//replace.cpp
#include<bits/stdc++.h>
using namespace std;

string s[10005][2];
int N,q;

struct Node{
	int l,r;
	bool tag=0;
};

bool cmp(Node x,Node y){
	if(x.l != y.l)return x.l>y.l;
	else return x.r>y.r;
}

int find(string str, char f){
	for(int i=0;i<str.length();i++){
		if(str[i]==f)return i;
	}
	return -1;
}

void sl(){
	string a,b;
	int index=0;
	Node ans[10005];
	cin>>a>>b;
	const int x=a.length();
	char tag;
	for(int i=0;i<x;i++){
		if(a[i]!=b[i])tag=a[i];
	}
	int fa=find(a,tag);
	int fb=find(b,tag);
	for(int i=0;i<N;i++){
		if(s[i][0].length() > a.length())continue;
		if(abs(fa-fb)>s[i][0].length())continue;
		int f0=find(s[i][0],tag);
		int f1=find(s[i][0],tag);
		if(f0==-1 || f1==-1)continue;
		if(fa<f0 || fb<f1)continue;
		if(fa-fb != f0-f1)continue;
		ans[index].l=f0;
		ans[index].r=fa;
		index++;
	}
	sort(ans,ans+index,cmp);
	for(int i=0;i<index-1;i++)
		if(ans[i].l == ans[i+1].l && ans[i].r == ans[i+1].r)
			ans[i+1].tag=1;
	int index2=0;
	for(int i=0;i<index;i++)
		if(ans[i+1].tag==0) index2++;
	cout<<index2<<endl;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>N>>q;
	for(int i=0;i<N;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--)sl();
}
