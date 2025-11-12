#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("numder.out","w",stdout);
	string n;
	cin>>n;
	vector<int> v={};

	for(int i=0;i<n.length();i++){
		if(n[i]-'0'<=9&&n[i]-'0'>=0)v.push_back(n[i]-'0');
	}sort(v.begin(),v.begin()+v.size());
	for(int i=v.size()-1;i>=0;i--)cout<<v[i];
	return 0;
}
