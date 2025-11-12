#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
int bfs(string t1,string t2) {
	int ans=0;
	map<string,bool> ds;
	queue<string> q;
	q.push(t1);
	ds[t1]=1;
	while(!q.empty()) {
		string u=q.front();
		q.pop();
		//	cout<<u<<endl;
		for(int i=1; i<=n; i++) {
			if(t1.find(s[i][1],0)==18446744073709551615)continue;
			string x=t1.substr(0,(int)t1.find(s[i][1],0));
			string y=s[i][2];
			string z=t1.substr(t1.find(s[i][1],0)+s[i][1].size());
			cout<<u<<" "<<x<<" "<<y<<" "<<z<<endl;
			if((x+y+z)==t2)ans++;
			else if(ds[x+y+z]==0) {
				q.push(x+y+z);
				ds[x+y+z]=1;
			}
		}

	}
	return ans;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++)cin>>s[i][1]>>s[i][2];
	while(q--) {
		string t1,t2;
		cin>>t1>>t2;
		cout<<bfs(t1,t2)<<endl;
	}
	return 0;
}
