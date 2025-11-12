#include <bits/stdc++.h>
using namespace std;
const int N=5e6+10;
int n,q,tot,p;
string a[N],b[N],x,y;
int nxt[N][26];
bool ed[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<"0\n";continue;
		}
		int st=-1,ed;
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				if(st==-1)st=i;
				ed=i;
			}
		}
		int ct=0;
		for(int j=0;j<x.size();j++){
			for(int i=1;i<=n;i++){
				bool f=1;
				for(int k=0;k<a[i].size();k++){
					if(a[i][k]!=x[j+k]||b[i][k]!=y[j+k]){
						f=0;
						break;
					}
				}
				if(f&&j<=st&&j+a[i].size()-1>=ed){
					ct++;
				}
			}
		}
		cout<<ct<<'\n';
	}
	return 0;
}
