#include<bits/stdc++.h>
using namespace std;
int n,q,num,k;
string x,y;
set<string> a;
set<string> b;
void dfs(int l,int r){
	string o,oo;
	for(int i=l;i<=r;i++){
		o+=x[i];
		oo+=y[i];
	}
	if(a.count(o)&&b.count(oo)){
		num++;
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		a.insert(x);
		b.insert(y);
	}
	while(q--){
		cin>>x>>y;
		k=x.size();
		num=0;
		int p=0,l,r;
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				if(p==1){
					r=i;
				}else{
					l=i;
					p=1;
				}
			}
		}
		for(int i=l;i>=0;i--){
			for(int j=r;j<k;j++){
				dfs(i,j);
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
