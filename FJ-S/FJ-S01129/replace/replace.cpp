#include<bits/stdc++.h>
using namespace std;
int N,Q;
string s1[200005],s2[200005],S,To_s;
int cnt=0;
int dfs(int id,string s){
	int l=s1[id].size();
	for(int i=0;i+l-1<s.size();i++){
		string ss=s.substr(i,l);
		bool b=1;
		for(int j=0;j<l;j++){
			if(ss[j]!=s1[id][j]){
				b=0;
				break;
			}
		}
		if(b==1){
			for(int j=0;j<l;j++){
				s[i+j]=s2[id][j];
			}
			int d=1;
			for(int j=0;j<s.size();j++){
				if(s[j]!=To_s[j]){
					d=0;
				}
				s[j]=S[j];
			}
			cnt+=d;
		}
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> N >> Q;
	for(int i=1;i<=N;i++){
		cin >> s1[i] >> s2[i];
	}
	while(Q--){
		cnt=0;
		cin >> S >> To_s;
		for(int i=1;i<=N;i++){
			dfs(i,S);
		}
		cout << cnt << endl;
	}
}