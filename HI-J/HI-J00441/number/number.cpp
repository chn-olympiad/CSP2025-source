#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			m.push_back((s[i]-'0'));
		}
	}
	sort(m.begin(),m.end(),cmp);
	for(auto i:m){
		cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

