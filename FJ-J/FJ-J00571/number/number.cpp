#include<bits/stdc++.h>
using namespace std;
vector<int> a;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char b;
	while(cin>>b){
		if(b>='0'&&b<='9') a.push_back(b-'0');
	}
	sort(a.begin(),a.end(),cmp);
	for(auto it:a){
		cout<<it;
	}
	return 0;
}
