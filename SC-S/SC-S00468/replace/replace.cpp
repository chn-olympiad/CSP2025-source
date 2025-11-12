#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][2];
bool check(string t1,string t2,string s1,string s2){
	if(t1.find(s1)!=string::npos){
		if(t2.find(s2)!=string::npos){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	while(q--){
		string t1,t2;
		int tot=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			if(check(t1,t2,s[i][0],s[i][1])) tot++;
		}
		cout<<tot<<'\n';
	}
	return 0;
}