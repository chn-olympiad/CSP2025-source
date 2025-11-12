#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int n,q;
map<string,string>a,b;
map<string,int>vis;

//void runa(queue<string>&q,string s,string key,int i){
//	if(i>=s.size()) return;
//	if((long long)s.substr(i).find(key)!=-1ll){
//		runa(q,s,key,(int)s.substr(i).find(key)+i+1);
//		int r=vis[s]+1;
//		s=s.substr(0,(int)s.substr(i).find(key)+i)+a[key]+s.substr((int)s.substr(i).find(key)+i+(int)key.size());
//		if(!vis[s]){
//			q.push(s);
//			vis[s]=r;
//		}
//	}
//}
//
//void runb(queue<string>&q,string s,string key,int i){
//	if(i>=s.size()) return;
//	if(){
//		runb(q,s,key,(int)s.substr(i).find(key)+i+1);
////		int r=vis[s]+1;
//		s=s.substr(0,(int)s.substr(i).find(key)+i)+b[key]+s.substr((int)s.substr(i).find(key)+i+(int)key.size());
////		if(!vis[s]){
////			q.push(s);
////			vis[s]=r;
////		}
//	}
//}

int dfs(string s1,string s2){
	if(s1==s2) return 1;
	int r=0;
	for(auto kv:a) if((long long)s1.find(kv.first)!=-1ll){
		int i=0;
		string s;
		while(i<s1.size()&&(long long)s1.substr(i).find(kv.first)!=-1ll){
			s=s1;
			s=s.substr(0,(int)s.substr(i).find(kv.first)+i)+b[kv.first]+s.substr((int)s.substr(i).find(kv.first)+i+(int)kv.first.size());
			r+=dfs(s,s2);
			i=(int)(s.substr(i).find(kv.first))+i+1;
		}
	}
	return r;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1;
		cin>>a[s1];
		b[a[s1]]=s1;
	}
	while(q--){
		cin>>s1>>s2;
//		vis[s1]=1;
//		queue<string>q;
//		string f;
//		q.push(s1);
//		while(!q.empty()){
//			f=q.front();
//			q.pop();
//			for(auto kv:b) if((long long)f.find(kv.first)!=-1ll) runb(q,f,kv.first,0);
//		}
//		cout<<vis[s2]<<endl;
//		for(auto kv:vis) kv.second=0;
		cout<<dfs(s1,s2)<<endl;
	}
}

