#include<bits/stdc++.h>
using namespace std;

int n,m,ans=9000000;

struct l{
	string a,b;
}p[200010];

string q1,q2;

void dfs(int cnt,string k){
	if(cnt>=ans){
		return;
	}
	for(int i=1;i<=n;i++){
		int pos=0;
		while(-1!=k.find(pos,k.length()-1,p[i].a)){
			string m;
			m=k;
			m.replace(p[i].b,k.find(pos,k.length()-1,a),p[i].b.length());
			dfs(cnt+1,m);
		}
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].b;
		dfs(0,q1);
	}
	for(int i=1;i<=n;i++){
		cin>>q1>>q2;
		dfs(0,q1);
	}
}
