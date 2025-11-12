#include <bits/stdc++.h>
using namespace std;
int n,t;
struct xx{
	string s,ss;
}q[200002];
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>t;
	for(int i=0;i<n;i++){
		cin>>q[i].s>>q[i].ss;
	}
	for(int i=0;i<t;i++){
		cin>>a>>b;
		if(a==q[i].s&&q[i].ss==b){
			cout<<"1"<<endl;
			continue;
		}
		cout<<"0"<<endl;
	}
	return 0;
}
