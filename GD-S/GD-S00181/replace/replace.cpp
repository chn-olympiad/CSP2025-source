#include <bits/stdc++.h>
using namespace std;
string replace1(string s,string s1,string s2){
	int index=s.find(s1);
	int size=s1.size();
	for (int i=index;i<=index+size-1;i++){
		s[i]=s2[i-index];
	}
	return s;
}
int equ(string a,string b){
	for (int i=0;i<a.size();i++){
		if (a[i]!=b[i]) return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	vector<pair<string,string>> m;
	for (int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		m.push_back({a,b});
	}
	for (int j=1;j<=q;j++){
		string s1,s2;
		cin>>s1>>s2;
		int cnt=0;
		for (pair<string,string> i:m){
			if (s1.find(i.first)!=-1){
				string ns1=replace1(s1,i.first,i.second);
				if (equ(ns1,s2)) cnt++; 
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}


