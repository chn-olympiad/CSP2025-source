#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string>s;
string t,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		s[a]=b;
	}
	while(q--){
		cin>>t>>t2;
		int cnt=0;
		int l=t.size();
		for(auto v:s){
			if(t==v.first&&v.second==t2) cnt++;
		}
		for(int i=0;i<l;i++){
			for(int j=i;j<l;j++){
				string x=t.substr(0,i-0);
				string y=t.substr(i,j-i);
				string z=t.substr(j,t.size()-j);
				for(auto v:s){
					if(y==v.first&&(x+v.second+z)==t2) cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	
	
	
	
	return 0;
}
