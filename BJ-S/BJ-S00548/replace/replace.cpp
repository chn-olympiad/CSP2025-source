#include<bits/stdc++.h>
using namespace std; 
int t[100005],sum=0,n,q;
string t1,t2,s1[100005],s2[100005];
struct point{
	string x;
	int cnt;
};
void bfs(){
	queue<point> q;
	q.push({t1,0});
	while(!q.empty()){
		point f=q.front();
		q.pop();
		if(f.x==t2){
			cout<<f.cnt<<endl;
			return ;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=f.x.size()-s1[i].size()+1;j++){
				if(f.x.substr(j,s1[i].size())==s1[i]){
					string tmp=f.x;
					f.x.erase(j,s1[i].size());
					f.x.insert(j,s2[i]);
					string tmp1=f.x;
					q.push({tmp1,f.cnt+1});
				}
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		bfs();
	}
	return 0;
}