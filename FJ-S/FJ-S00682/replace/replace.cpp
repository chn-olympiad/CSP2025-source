#include<bits/stdc++.h>
using namespace std;
int n,q;
string m[2],x,y;
string s(int i,int l){
	string a;
	for(;i<=l;i++)a+=y[i];
	return a;
}
string s1(int i,int l){
	string a;
	for(;i<=l;i++)a+=x[i];
	return a;
}
void s2(int i,int l){
	for(;i<=l;i++)x[i]+=y[i];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	cin>>m[0]>>m[1];
	while(q--){
		cin>>x>>y;
		for(int i=1;i<x.size();i++){
			if(s(i,i+m[0].size()-2)==m[1]&&s1(i,i+m[0].size()-2)==m[0])s(i,i+m[0].size()-2);
		}
		if(x==y)cout<<1<<'\n';
		else cout<<0<<'\n';
	}
} 
