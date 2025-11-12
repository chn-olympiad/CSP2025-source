#include<bits/stdc++.h>
using namespace std;
map<string,int> f;
map<string,string> mp;
string fun(string a,string b){
	int p=a.find(b);
	b=mp[b];
	for(int i=p;i<p+b.size();i++){
		a[i]=b[i-p];
	}
	return a;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		f[a]=1;
		mp[a]=b;
	} 
	while(q--){
		long long ans=0;
		string x,y;
		cin>>x>>y;
		for(int i=0;i<x.size();i++){
			string s="";
			for(int j=i;j<x.size();j++){
				s+=x[j];
				if(f[s]){
					string t=fun(x,s);
					if(t==y) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
	//rp++ 
} 
