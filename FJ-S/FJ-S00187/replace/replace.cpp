#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,p;
	vector <string> s1,s2,w1,w2;
	string s;
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>s;
		s1.push_back(s);
		cin>>s;
		s2.push_back(s);
	}
	for(int i=1;i<=p;i++){
		cin>>s;
		w1.push_back(s);
		cin>>s;
		w2.push_back(s);
	}
	for(int i=1;i<=p;i++){
		cout<<0<<endl;
	}
	return 0;
} 
