//replace.cpp
#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#include<vector>
using namespace std;
int main(){
	freopen("replace1.in","r",stdin);
	freopen("replace1.out","w",stdout);
	int n,q,cnt;
	cin>>n>>q;
	string a,b;
	vector<string> la,ln;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		la.push_back(a);
		ln.push_back(b);
	}
	for(int i=0;i<q;i++){
		cnt=0;
		cin>>a>>b;
		for(auto j:la){
			if(a.find(j) && b.find(j)) cnt++;
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
