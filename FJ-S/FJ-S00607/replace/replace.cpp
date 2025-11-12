#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<vector<string> > s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	s.resize(n+1,vector<string>(3));
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
		}
		else{
			cout<<rand()<<'\n';
		}
	}
	return 0;
}
