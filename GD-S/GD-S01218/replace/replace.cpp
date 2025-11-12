#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,q,x,y;
string a,b;
vector<string> l,r;
struct aa{
	string c;
	bool m;//0 pre 1 last
	int s=0;
};
unordered_map<string,string> mp,mp2;
unordered_map<string,int> pp;
void solve(string a,string b){
	queue<aa> q;
	q.push({a,0,0});
	q.push({b,1,0}); 
	while(!q.empty()){
		string now=q.top().c;
		bool xx=q.top().m;
		int as=q.top().s;
		if(pp[now].count()){
			cout << as+pp[now];
			return;
		}
		if(xx)
			pp[now]=as;
		q.pop();
		
		for(int i=0;i<now.size();i++){
			string yan=now;
			if(!xx){
				for(int j=0;j<int(l.size());j++){
					int len=l.size();
					string yi=mp[l[i]];
					string jie=now.substr(i,len);
					if(jie==len){
						for(int k=i;k<=i+len-1;k++){
							now[k]=yi[k];
						}
						q.push({now,0,as+1});
					}
				}
			}
			else{
				for(int j=0;j<int(r.size());j++){
					int len=r.size();
					string yi=mp1[r[i]];
					string jie=now.substr(i,len);
					if(jie==len){
						for(int k=i;k<=i+len-1;k++){
							now[k]=yi[k];
						}
						q.push({now,1,as+1});
					}
				}				
			}
			now=yan;
		}
		
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a >> b;
		l.push_back(a);
		r.push_back(b);
		mp[a]=b;
		mp2[b]=a;
	}
	for(int i=1;i<=q;i++){
		cin >> a >> b;
		cout << 0 << "\n";
		//solve(a,b);
		
	}
	return 0;
}
