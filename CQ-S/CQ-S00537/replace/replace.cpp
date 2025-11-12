#include<bits/stdc++.h>
using namespace std;
int n,t,ans=2e9;
string x[200005],y[200005];
struct node{
	string s;
	int val;
};
unordered_map<string,int> mp;
queue<node> q;
void bfs(string b,string e){
	mp.clear();
	q.push({b,0});
	mp[b]=1;
	int cnt=0;
	while(!q.empty()){
		node kkk=q.front();
		if(kkk.s==e){
			cnt++;
			q.pop();
			continue;
		}
		q.pop();
		if(kkk.val>=n){
			continue;
		}
		string ss=kkk.s;
		for(int i=0;i<ss.size();i++){
			for(int j=1;j<=n;j++){
				string qhx="";
				if(i!=0){
					qhx+=ss.substr(0,i);
				}
				qhx+=y[j];
				if(i+x[j].size()-1<ss.size()-1){
					qhx+=ss.substr(i+x[j].size(),ss.size()-i-x[j].size());
				}
				if(ss.substr(i,x[j].size())==x[j]){
					mp[qhx]=kkk.val+1;
					q.push({qhx,kkk.val+1});
				}
			}
		}
	}
	cout<<cnt<<'\n';
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		cin>>y[i];
	}
	while(t--){
		ans=2e9;
		string t,t2;
		cin>>t>>t2;
		if(t.size()!=t2.size()){
			cout<<"0"<<'\n';
			continue;
		}
		bfs(t,t2);
	}
	return 0;
}
