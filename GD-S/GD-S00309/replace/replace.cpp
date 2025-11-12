#include<bits/stdc++.h>
using namespace std;
struct node{
	string u,v;
}p[200005];
struct node2{
	string t;
	bool x;
};
int ans,n;
void bfs(string st,string ed){
	map<string,int> m;
	queue<node2> q;
	q.push({st,0});
	m[st]=1;
	while(!q.empty()){
		string now=q.front().t;
		bool g=q.front().x;
		q.pop();
		if(now==ed){
			ans++;
			continue;
		}
		if(g==1){
			continue;
		}
		m[now]=1;
		for(int i=1; i<=n; i++){
			string a=p[i].u;
			string b=p[i].v;
			if(now.find(a)!=string::npos){
				string s=a;
				s=now.replace(now.find(a),1,b);
				if(m[s]==0){
					q.push({s,0});
				}
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t;
	scanf("%d %d",&n,&t);
	for(int i=1; i<=n; i++){
		string a,b;
		cin>>a>>b;
		p[i].u=a;
		p[i].v=b;
	}
	while(t--){
		ans=0;
		string l,r;
		cin>>l>>r;
		bfs(l,r);
		printf("%d\n",ans);
	}
	return 0;
}
