#include<bits/stdc++.h>
using namespace std;
string x[10007],y[10007];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	while(q--){
		string X,Y;
		cin>>X>>Y;
		int cnt = 0;
		queue<string> Q;
		Q.push(X);
		while(!Q.empty()){
			string cur = Q.front();
			if(cur == Y) cnt++;
			Q.pop();
			for(int i=1;i<=n;i++){
				if(cur.find(x[i]) >= cur.size()) continue;
				for(int j=0;j<x[i].size();j++){
					cur[j+cur.find(x[i])] = y[i][j];
				}
				Q.push(cur);
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
