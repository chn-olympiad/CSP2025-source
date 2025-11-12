#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>a;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(auto v:a){
		cout<<v;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
