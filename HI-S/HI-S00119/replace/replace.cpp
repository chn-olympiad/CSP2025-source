#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200010];
string b[200010];
bool ch(string f,string g){
	if(f.size()<g.size()){
		return false;
	}
	int k=0;
	for(int i=0;i<f.size();i++){
		if(f[i]==g[k]){
			k++; 
			if(k>=g.size()){
				return true;
			}
		}
		else{
			k=0;
			if(f.size()-i<g.size()){
				return false;
			}
		}
	} 
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]; 
	}
	while(q--){
		int ans=0;
		string x,y;
		cin>>x>>y;
		int u,v;
		bool z=false;
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				if(!z){
					z=true;
					u=i;
				}
				else{
					v=i;
				}
			}
		} 
		string c,d;
		for(int i=u;i<=v;i++){
			c+=x[i];
			d+=y[i];
		}
		for(int i=0;i<n;i++){
			if(ch(a[i],c)){
				if(ch(x,a[i])&&ch(b[i],d)&&ch(y,b[i])){
					ans++;
				}
			}
		} 
		cout<<ans<<'\n';
	} 
	return 0;
} 
