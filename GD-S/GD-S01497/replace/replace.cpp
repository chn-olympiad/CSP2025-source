#include<bits/stdc++.h>
using namespace std;
long long n,q;
vector<string> v;
map<string,string>m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		m[a]=b;
		v.push_back(a);
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		int cs=0;
		for(int j=0;j<v.size();j++){
			string rc=v[j];
			string rc2=a;
			long long wz=rc2.find(v[j]);
			if(wz<rc2.size()){
				rc2=rc2.substr(0,wz)+m[v[j]]+rc2.substr(wz+v[j].size(),rc2.size());
				if(rc2==b){
					cs++;
				}
			}
			
		}
		cout<<cs<<endl;
	}
	return 0;
}
