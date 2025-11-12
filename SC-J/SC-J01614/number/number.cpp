#include<bits/stdc++.h>
using namespace std;
vector<int> a;
string s,k;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			int x=s[i]-'0';
			a.push_back(x);
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}

	return 0;
}
