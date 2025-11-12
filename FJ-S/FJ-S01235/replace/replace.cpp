#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[100005][2];
vector<int> fid(string x,string p){
	vector<int>v;
	for(int i=0;i<(int)x.size()-p.size()+1;i++){
		if(x.substr(i,p.size())==p){
			v.push_back(i);
		}
	}
	return v;
}
string th(string a,int n,string p){
	for(int i=n;i<n+p.size();i++){
		a[i]=p[i-n];
	}
	return a;
}
int cm(string x,string y){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(x.size()<a[i][0].size())	continue;
		vector<int>v=fid(x,a[i][0]);
		if(!v.size())continue;
		for(int k=0;k<v.size();k++){
			if(th(x,v[k],a[i][1])==y)cnt++;
		}
	}
	return cnt;
}
int main(){
  	freopen("replace.in","r",stdin);
  	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	} 
	while(q--){
		string x,y;
		cin>>x>>y;
		cout<<cm(x,y)<<endl; 
	}
	return 0;
}

