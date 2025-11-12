#include<bits/stdc++.h >
using namespace std;
string s;
vector<int> a;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0; i < l; i++){
		if(s[i]>='0' && s[i]<='9'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	l = a.size();
	bool e=0;
	for(int i=0; i < l; i++){
		if(a[i]==0 && !e) continue;
		cout<<a[i];
		e = 1;
	}
	if(e == 0) cout<<0;
	return 0;
}
