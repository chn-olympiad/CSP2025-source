#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool cmp(int t1,int t2){
	return t1>t2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			v.push_back(s[i]-'0');
		}
 	}
 	sort(v.begin(),v.end(),cmp);
 	vector<int>::iterator it = v.begin();
 	for(it;it!=v.end();it++){
 		cout<<*(it);
	}
}
