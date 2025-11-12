#include<bits/stdc++.h>
#include<map>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	map<char,char>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]){
				q[a[i]]=b[i];
				q[b[i]]=a[i];
			}
		}
	}
	while(m--){
		string x,y;
		cin>>x>>y;
		long long ans=0;
		for(int i=0;i<x.size();i++){
			char a=x[i];
			char b=y[i];
			if(a!=b){
				if(q[a]==b){
					ans++;
				}
			}
		}
		cout<<ans; 
	}
	return 0;
}
